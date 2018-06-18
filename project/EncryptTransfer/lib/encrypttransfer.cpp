//
// Created by a on 4/14/18.
//


#include <encrypttransfer.h>
namespace enp {

#define SYSTEM CONST VALUE

    const uint8_t ServerNoReady = 0;
    const uint8_t ServerReady = 1;
    const uint8_t ServerClose = 2;
    const uint8_t ENDFLAG = 0xff;
    const uint32_t serverlistenaddr = htonl(INADDR_ANY);
    const uint16_t DATALEN = 128;
    const uint16_t FILENAMELEN=4096;

#define SYSTEM_ENV_VALUE

    unsigned int ClientSleepTime=5;
    uint32_t serverport = 2586;
    pthread_t pid[MAXPID];
    queue<uint32_t> freepid;
    pthread_mutex_t freepidlock;
    bool serverreject=false;
    string k1024="key/1024.rsa";
    string k2048="key/2048.rsa";
    string k4096="key/4096.rsa";

   uint16_t g2x(unsigned char* data,mpz_class mp) {
        uint16_t len = 0, i, j;
        unsigned char k;
        mpz_class tmp = mp;
        while (tmp != 0) {
            len++;
            tmp>>=8;
        }
        for (i = 0; i < len; i++) {
            for (j = 0, k = 0; j < 8; j++) {
                tmp=mp%2;
                if (tmp == 1)
                    k ^= (1 << j);
                mp /= 2;
            }
            data[i]=k;
        }
        return len;
    }
    mpz_class x2g(unsigned char* data, uint16_t len) {
        int i;
        mpz_class ans = 0;
        for (i = len - 1; i >= 0; i--) {
            ans<<=8;
            //ans*=16;
            ans+=data[i];
        }
        return ans;
    }

    void Header::ServerSet(mpz_class c, mpz_class d) {
        unsigned char data[4096];
        uint16_t len;
        len = g2x(data,c);
        memcpy(this->keyn, data, sizeof(uint8_t) * (4096 / 8));
        lenkeyn=len;
        len = g2x(data,d);
        memcpy(this->keyd, data, sizeof(uint8_t) * (4096 / 8));
        lenkeyd=len;
    }

    void Header::ClientSet(mpz_class akey,char *f, unsigned long long s) {
        unsigned char data[4096];
        uint16_t len;
        len=g2x(data,akey);
        memcpy(aeskey,data,sizeof(aeskey));
        lenaeskey=len;
        memcpy(filename,f,sizeof(filename));
        filesize=s;
    }


    void Dataheader::set(uint8_t b, unsigned long long c) {
        this->plaintextlen = b;
        this->ack = c;
    }
    void funparm::set(uint32_t a, uint32_t b , int c){
        pidind=a;   fd=b;   encodemethod=c;
    }

}

void enp::ctrlc(int sig){
    pthread_mutex_lock(&freepidlock);
    char c;
    if(freepid.size()!=MAXPID){
        cout<<freepid.size()<<endl<<MAXPID<<endl;
        pthread_mutex_unlock(&freepidlock);
        cerr<<"\nThere still some transfer process\n";
        while(1){
            cerr<<"Are you sure to cancel them?(Y\\N)\n";
            c=getchar();
            if(c=='Y'||c=='y'||c=='N'||c=='n')break;
        }
        if(c=='Y'||c=='y')exit(1);
        cerr<<"transfer continue\n";
        while(1){
            cerr<<"Do you want to stop when exist transfer compelete?(Y\\N)\n";
            c=getchar();
            if(c=='Y'||c=='y'||c=='N'||c=='n')break;
        }
        if(c=='Y'||c=='y')serverreject=true;
    }
    else exit(1);
}

void enp::clear() {
#ifdef LINUX
    system("clear");
#endif
#ifdef WINDOWS
    system("clc");
#endif
}