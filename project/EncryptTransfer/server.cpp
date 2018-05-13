//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>

using namespace enp;


NET server;

void* serverfun(void *args) {
    signal(SIGPIPE, SIG_IGN);
    uint32_t pidind = ((funparm *) args)->pidind;
    uint32_t fd = ((funparm *) args)->fd;;
    int encodemethod=((funparm *)args)->encodemethod;
    char buffer[5000];
    char filename[4096];
    mpz_class tmp;
    char* tmp1;

    RSA coder;
    coder.setkey(encodemethod);
    Dataheader DH;
    Header H;
    pair<mpz_class,mpz_class>p=coder.getpublickey();
    H.set(p.first,p.second);
    tmp1=(char*)&H;
#ifdef DEBUG
    cout<<sizeof(H)<<endl;
#endif
    if(!Send(tmp1,sizeof(H),fd)){
        close(fd);
        cerr<<"Transfe closed\n";
        while (freepidlock);
        freepidlock=true;
        freepid.push(pidind);
        freepidlock= false;
        return (void *) NULL;
    }

    tmp1=filename;
#ifdef DEBUG
    cout<<sizeof(filename)<<endl;
#endif
    if(!Recv(tmp1,FILENAMELEN,fd)){
        close(fd);
        cerr<<"Transfe closed\n";
        while (freepidlock);
        freepidlock=true;
        freepid.push(pidind);
        freepidlock= false;
        return (void *) NULL;
    }

    DH.end = 0;
    IO fout(filename, ios::out | ios::binary);
    Dataheader *tmp2 = &DH;
    tmp1 = buffer;
    while (DH.end!=1) {
        if (!Recv(tmp2, sizeof(DH), fd)){
            close(fd);
            cerr<<"Transfe closed\n";
            while (freepidlock);
            freepidlock=true;
            freepid.push(pidind);
            freepidlock= false;
            return (void *) NULL;
        }
        if (!Recv(tmp1, DH.ciphertextlen, fd)){
            close(fd);
            cerr<<"Transfe closed\n";
            while (freepidlock);
            freepidlock=true;
            freepid.push(pidind);
            freepidlock= false;
            return (void *) NULL;
        }
#ifdef DEBUG
        cout<<buffer<<endl;
#endif
        tmp = x2g(buffer, DH.ciphertextlen);
#ifdef DEBUG
        cout<<"密文 ："<<tmp<<endl;
#endif
        tmp=coder.decode(tmp);
#ifdef DEBUG
        cout<<"明文 ："<<tmp<<endl;
#endif
        fout.setsize(DH.plaintextlen);
        fout << tmp;
    }
    if(!Send(&ENDFLAG,sizeof(ENDFLAG),fd))
        cerr<<"Transfer fail\n";
    else cerr<<"Transfer Compelete\n";
    close(fd);
    while (freepidlock);
    freepidlock = true;
    freepid.push(pidind);
    freepidlock = false;
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
    cout << "server ready for transfer data...\n";
    while (1) {
        p = server.Listen();
        funparm fp;
        fp.set(p.first,p.second,encodemethod);
        pthread_create(&pid[p.first], NULL, serverfun, (void *)&fp);
    }
    return 0;
}