//
// Created by a on 4/14/18.
//


#include <encrypttransfer.h>
namespace enp {
    uint8_t ServerNoReady = 0;
    uint8_t ServerReady = 1;
    unsigned int ClientSleepTime=5;
    const uint8_t ENDFLAG = 0xffff;
    const uint16_t DATALEN = 128;
    uint32_t serverport = 2586;
    uint32_t serverlistenaddr = htonl(INADDR_ANY);
    pthread_t pid[MAXPID];
    queue<uint32_t> freepid;
    bool freepidlock = false;
    string k1024="key/1024.rsa";
    string k2048="key/2048.rsa";
    string k4096="key/4096.rsa";

   uint16_t g2x(char* data,mpz_class mp) {
        uint16_t len = 0, i, j, k;
        mpz_class tmp = mp;
        while (tmp != 0) {
            len++;
            tmp /= 16;
        }
        for (i = 0; i < len; i++) {
            for (j = 0, k = 0; j < 4; j++) {
                tmp=mp%2;
                if (tmp == 1)
                    k ^= (1 << j);
                mp /= 2;
            }
            if (k >= 0 && k <= 9) data[i] = (uint8_t)('0' + k);
            else data[i] = (uint8_t)('A' + k - 10);
        }
        return len;
    }
/*
    mpz_class x2g(char *data, uint16_t len) {
        int i, k;
        mpz_class ans = 0;
        for (i = len - 1; i >= 0; i--) {
            if (data[i] >= '0' && data[i] <= '9')k = data[i] - '0';
            else k = data[i] - 'A' + 10;
            //ans=ans*16;
            mpz_class tmp;
            mpz_mul_ui(tmp.get_mpz_t(),ans.get_mpz_t(),16);
            mpz_add_ui(tmp.get_mpz_t(),ans.get_mpz_t(),k);
            ans=tmp;
            //ans = ans + k;
        }
        return ans;
    }
*/
    mpz_class x2g(string data, uint16_t len) {
        int i, k;
        mpz_class ans = 0;
        for (i = len - 1; i >= 0; i--) {
            if (data[i] >= '0' && data[i] <= '9')k = data[i] - '0';
            else k = data[i] - 'A' + 10;
            ans<<=4;
            //ans*=16;
            ans+=k;
        }
        return ans;
    }

    void Header::set(mpz_class c, mpz_class d) {
        char data[4096];
        uint16_t len;
        len = g2x(data,c);
        memcpy(this->keyn, data, sizeof(uint8_t) * (4096 / 8));
        lenkeyn=len;
        len = g2x(data,d);
        memcpy(this->keyd, data, sizeof(uint8_t) * (4096 / 8));
        lenkeyd=len;
    }

    void Dataheader::set(uint16_t a, uint8_t b, uint8_t c) {
        this->ciphertextlen = a;
        this->plaintextlen = b;
        this->end = c;
    }
    void funparm::set(uint32_t a, uint32_t b , int c){
        pidind=a;   fd=b;   encodemethod=c;
    }


}

void enp::clear() {
#ifdef LINUX
    system("clear");
#endif
#ifdef WINDOWS
    system("clc");
#endif
}