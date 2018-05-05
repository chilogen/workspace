//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>
using namespace enp;


void help() {
    clear();
    std::cout << "Usage :\n";
    std::cout << "sendTo <server IP> <encode method>  <file> <key_path>\n";
    std::cout << "encode method:\n";
    std::cout << "1----1024 bits key\n";
    std::cout << "2----2048 bits key\n";
    std::cout << "3----4096 bits key\n";
}

bool checkparm(int argv,char** argc) {
    if (argv != 5)return 0;
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
    uint8_t *encodemethod = (uint8_t *) &argc[2][0];
    char *filename = argc[3];

    RSA coder;
    coder.setkey(*encodemethod);

    pair<mpz_class,mpz_class>p=coder.getpublickey();

    NET client;
    Header H;
    H.set(*encodemethod, (unsigned char *) filename, p.first, p.second);
    client.init(serverip, serverport, CLIENT);
    client.Connect(H);

    IO fin(filename, ios::in | ios::binary);
    char buf[4096];
    mpz_class tmp;
    uint8_t isend = 0, state;
    Dataheader DH;
    pair<unsigned char *, uint16_t> p1;

    while (1) {
        state = fin >> tmp;
        tmp = coder.encrypt(tmp);
        p1 = g2x(tmp);
        isend = fin.eof();
        DH.set(p1.second, state, isend);
        client.Send(&DH, sizeof(DH));
        client.Send(p1.first, p1.second * 8);
        delete p1.first;
        if (isend)break;
    }
    return 0;
}