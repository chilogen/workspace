//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>
using namespace enp;
typedef unsigned long long ull;

void help() {
    clear();
    std::cout << "Usage :\n";
    std::cout << "sendTo <server IP>  <file>\n";
}

bool checkparm(int argv,char** argc) {
    if (argv != 3)
        return 0;
    /*
     *
     *
     */
    return 1;
}

unsigned long long totle,schedule;

ull filesize(char *path){
    struct stat filestat;
    if(stat(path,&filestat)<0)return -1;
    return (filestat.st_size*8/128+1);
}
unsigned long long lastack = 0, nowack = 0, lastime, nowtime,startime;
double all;
void showbar() {
    char bar[5000];
    double speed = 0, done;
    int len, i, j, percent;
    struct winsize win;
    nowack = schedule;
    if (nowack == lastack)return;
    done = ((nowack - lastack) * 16) / 1024.0 / 1024.0;
    nowtime = time(NULL);
    speed = done / (double) (nowtime - lastime);
    lastack = nowack;
    lastime = nowtime;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    if (win.ws_col < 30) {
        printf("\rToo narrow to display stat");
        return;
    }
    len = win.ws_col - 20;
    percent = (int) (((double) nowack) / (double) (totle) * len);
    memset(bar, 0, sizeof(bar));
    bar[0]='[';
    for (i = 1; i < percent; i++)bar[i] = '+';
    for (i; i < len; i++)bar[i] = '-';
    bar[i] = ']';
    printf("\r");
    fflush(stdout);
    for (j = 0; j <= i; j++)printf("%c", bar[j]);
    printf("%.2lfMB/s", speed);
}

int main(int argv,char **argc) {
    if (!checkparm(argv, argc)) {
        help();
        return 0;
    }
    char *serverip = argc[1];
    char filename[4096];
    memcpy(filename,argc[2],sizeof(char)*strlen(argc[2]));
    unsigned char plaintext[AES_BLOCK_SIZE],ciphertext[AES_BLOCK_SIZE];

    NET client;
    client.init(serverip,serverport,CLIENT);
    client.Connect();

    IO fin(filename,ios::in|ios::binary);

    RSA rsacoder;
    AES aescoder(ENCRYPT);
    mpz_class keyn,keye,data;
    unsigned char aeskey[AES_BLOCK_SIZE];
    aescoder.genkey();
    aescoder.getkey(aeskey);

    Header H;
    Dataheader DH;

    //receive Header from server
    if(!Recv(&H,sizeof(H),client.fd)) {
        cerr << "SERVER ERROR\n";
        return 0;
    }
    rsacoder.setkey(x2g((unsigned char*)H.keyn,H.lenkeyn),x2g((unsigned char*)H.keyd,H.lenkeyd));
    pair<mpz_class,mpz_class>p=rsacoder.getpublickey();

    //Send header to server;
    totle=filesize(filename);schedule=0;
    H.ClientSet(rsacoder.encrypt(x2g(aeskey,16)),filename,totle);
    if(!Send(&H,sizeof(H),client.fd)){
        cerr << "SERVER ERROR\n";
        return 0;
    }

    //begin data transfer
    startime=nowtime=lastime=time(NULL);
    lastack=nowack=0;
    all=((double)totle*16)/1024.0/1024.0;
    cout<<"start transfer "<<filename<<endl;

    unsigned long long i,k=totle,ACK;
    uint8_t j;
    for(i=0;i<totle;i++){
        memset(plaintext,0,sizeof(plaintext));
        memset(ciphertext,0,sizeof(ciphertext));
        j=fin>>plaintext;
        aescoder.encrypt(plaintext,ciphertext);
        DH.set(j,i);
        if(!Send(&DH, sizeof(DH),client.fd)||!Send(ciphertext, 16,client.fd)){
            cerr<<"Server ERROR\n";
            return 0;
        }
        if(i%1000000!=0)continue;
        if(!Recv(&ACK,sizeof(unsigned long long),client.fd)){
            cerr<<"Server ERROR\n";
            return 0;
        }
        schedule=ACK;
        showbar();
    }

    cout<<"\nComplete!!!\n";
    nowtime=time(NULL);
    cout<<"used "<<nowtime-startime<<" seconds\n";
    cout<<"Transfer "<<all<<" M\n";
    cout<<"average speed :"<<all/(nowtime-startime)<<endl;
    return 0;
}