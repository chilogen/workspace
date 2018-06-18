//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>

using namespace enp;


NET server;

void* serverfun(void *args) {
    signal(SIGPIPE,SIG_IGN);
    uint32_t pidind = ((funparm *) args)->pidind;
    uint32_t fd = ((funparm *) args)->fd;
    int encodemethod=((funparm *)args)->encodemethod;

    char filename[4096];
    unsigned char plaintext[AES_BLOCK_SIZE],ciphertext[AES_BLOCK_SIZE];

    RSA rsacoder;
    AES aescoder(DECRYPT);
    pair<mpz_class,mpz_class>rsakey;
    unsigned char aeskey[AES_BLOCK_SIZE];


    //set coder and get key
    rsacoder.setkey(encodemethod);
    rsakey=rsacoder.getpublickey();

    Header H;
    Dataheader DH;

    //set Header and send it
    H.ServerSet(rsakey.first,rsakey.second);
    if(!Send(&H,sizeof(H),fd)){
        close(fd);
        cerr<<"Transfe closed\n";
        pthread_mutex_lock(&freepidlock);
        freepid.push(pidind);
        pthread_mutex_unlock(&freepidlock);
        return (void *) NULL;
    }
    //receive header from client
    if(!Recv(&H,sizeof(H),fd)){
        close(fd);
        cerr<<"Transfe closed\n";
        pthread_mutex_lock(&freepidlock);
        freepid.push(pidind);
        pthread_mutex_unlock(&freepidlock);
        return (void *) NULL;
    }
    g2x(aeskey,rsacoder.decode(x2g((unsigned char*)&H.aeskey,H.lenaeskey)));
    aescoder.setkey(aeskey);


    cout<<"Start recv "<<H.filename<<"......"<<endl;

    IO fout(H.filename,ios::out|ios::binary);
    unsigned long long ack,totle=H.filesize;
    for(ack=0;ack<totle;ack++){
        if(!Recv(&DH,sizeof(DH),fd)||!Recv(ciphertext,16,fd)){
            close(fd);
            cerr<<"Transfe closed\n";
            pthread_mutex_lock(&freepidlock);
            freepid.push(pidind);
            pthread_mutex_unlock(&freepidlock);
            return (void *) NULL;
        }
        fout.setsize(DH.plaintextlen);
        memset(plaintext,0,sizeof(plaintext));
        aescoder.decrypt(ciphertext,plaintext);
        fout<<plaintext;
        if(ack%1000000!=0)continue;
        if(!Send(&ack,sizeof(unsigned long long),fd)){
            close(fd);
            cerr<<"Transfe closed\n";
            pthread_mutex_lock(&freepidlock);
            freepid.push(pidind);
            pthread_mutex_unlock(&freepidlock);
            return (void *) NULL;
        }
    }

    pthread_mutex_lock(&freepidlock);
    freepid.push(pidind);
    pthread_mutex_unlock(&freepidlock);
    cout<<H.filename<<" compelete recv\n";
}

void help(){
    cout<<"Usage:\n";
    cout<<"server -m <encrypt method>\n";
    cout<<"-m 1-->1024\n";
    cout<<"-m 2-->2048\n";
    cout<<"-m 4-->4096\n";
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

int main(int argv,char **argc) {
    signal(SIGINT,ctrlc);
    if(!checkparm(argv,argc)){
        help();
        return 0;
    }
    pair<uint32_t, uint32_t> p;
    int encodemethod=argc[2][0]-'0';
    server.init((char *) NULL, serverport, SERVER);
    pthread_mutex_init(&freepidlock,NULL);
    cout << "server ready for transfer data...\n";
    while (1) {
        p = server.Listen();
        if(serverreject)continue;
        funparm fp;
        fp.set(p.first,p.second,encodemethod);
        pthread_create(&pid[p.first], NULL, serverfun, (void *)&fp);
    }
    pthread_mutex_destroy(&freepidlock);
    return 0;
}