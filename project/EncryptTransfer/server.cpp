//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>

using namespace enp;


NET server;

void* serverfun(void *args) {
    signal(SIGPIPE, SIG_IGN);
    uint32_t fd = ((funtionparm *) args)->fd;
    uint32_t pidind = ((funtionparm *) args)->pidind;
    uint8_t buffer[5000];

    RSA coder;
    Header H;
    Dataheader DH;

    Header *tmp1 = &H;
    if (!Recv(tmp1, sizeof(H), pidind, fd))return (void *) NULL;

    DH.end = 0;
    string filepath = (char *) H.filename;
    IO fout(filepath, ios::out | ios::binary);
    mpz_class tmp;
    while (!DH.end) {
        Dataheader *tmp2 = &DH;
        uint8_t *tmp1 = buffer;
        if (!Recv(tmp2, sizeof(DH), pidind, fd))return (void *) NULL;
        if (!Recv(tmp1, DH.ciphertextlen, pidind, fd))return (void *) NULL;
        tmp = x2g(buffer, DH.ciphertextlen);
        tmp = coder.decode(tmp);
        fout.setsize(DH.plaintextlen);
        fout << tmp;
    }
    close(fd);
    while (freepidlock);
    freepidlock = true;
    freepid.push(pidind);
    freepidlock = false;
}

int main() {
    pair<uint32_t, uint32_t> p;

    server.init((char *) NULL, serverport, SERVER);
    cout << "server ready for transfer data...\n";
    while (1) {
        p = server.Listen();
        pthread_create(&pid[p.first], NULL, serverfun, (void *) new funtionparm(p.first, p.second));
    }

    return 0;
}