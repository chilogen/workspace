//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>
using namespace enp;


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

int main(int argv,char **argc) {
    if (!checkparm(argv, argc)) {
        help();
        return 0;
    }
    char *serverip = argc[1];
    char *filename = argc[2];


    NET client;
    RSA coder;
    client.init(serverip, serverport, CLIENT);
    mpz_class keyn,keyd,tmp;
    Header H;

    client.Connect();
    void* tmp1=&H;
    cout<<sizeof(H)<<endl;
    if(!Recv(tmp1,sizeof(H),client.fd)){
        cerr<<"SERVER ERROR\n";
        return 0;
    }

    coder.setkey(x2g(H.keyn,H.lenkeyn),x2g(H.keyd,H.lenkeyd));
    cout<<sizeof(filename)<<endl;
    if(!Send(filename,FILENAMELEN,client.fd)){
        cerr<<"SERVER ERROR\n";
        return 0;
    }

    IO fin(filename, ios::in | ios::binary);
    uint8_t isend = 0, state;
    Dataheader DH;
    char data[4096];
    uint16_t len;

    while (1) {
        state = fin >> tmp;
#ifdef DEBUG
        cout<<"明文： "<<tmp<<endl;
#endif
        tmp=coder.encrypt(tmp);
#ifdef DEBUG
        cout<<"密文： "<<tmp<<endl;
#endif
        len = g2x((char*)data,tmp);
#ifdef DEBUG
        cout<<data<<endl;
#endif
        if(fin.eof())isend=1;
        else isend=0;
        DH.set(len, state, isend);
        if(!Send(&DH, sizeof(DH),client.fd)||!Send(data, len,client.fd)){
            cerr<<"Server ERROR\n";
            return 0;
        }
        if (isend)break;
    }
    tmp1=&isend;
    if(!Recv(tmp1,sizeof(isend),client.fd)||isend!=ENDFLAG)
        cerr<<"Transfer fail,try again\n";
    else cerr<<"Compelete!\n";
    close(client.fd);
    return 0;
}