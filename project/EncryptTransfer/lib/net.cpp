//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>

using namespace enp;

bool NET::check(char *ip, uint32_t port) {
    uint32_t p = 0;;
    unsigned char buf[sizeof(struct in6_addr)];
    if (!inet_pton(AF_INET, ip, buf))return 0;
    if (port <= 1024 || port > 65535)return 0;
    return 1;
}

bool NET::init(char *ip, uint32_t port, int sc) {
    if (sc == SERVER && this->check(ip, port)) {
        cerr << "wrong IP or PORT\n";
        return 0;
    }

    fd = socket(AF_INET, SOCK_STREAM, 0);


    memset(&sock, 0, sizeof(sock));
    sock.sin_family = AF_INET;
    sock.sin_port = htons(port);

    switch (sc) {
        case SERVER: {
            sock.sin_addr.s_addr = htonl(INADDR_ANY);
            bind(fd, (struct sockaddr *) &sock, sizeof(sock));
            listen(fd, 10);
            break;
        }
        case CLIENT: {
            inet_pton(AF_INET, ip, &sock.sin_addr);
            break;
        }
    }
}

void NET::Connect(Header H) {
    unsigned char buf[16];
    uint8_t handshake = 0;

    while (!handshake) {
        connect(fd, (struct sockaddr *) &sock, sizeof(sock));
        void *tmp = (void *) &handshake;
        if (!Recv(tmp, 8)) {
            cerr << "Server ERROR\n";
            exit(1);
        }
    }
    if (!Send(&H, sizeof(H))) { ;
        cerr << "Server ERROR\n";
        exit(1);
    }
}

pair<uint32_t,uint32_t > NET::Listen() {
    uint32_t nfd, pidind;
    while (true) {
        nfd = accept(fd, (struct sockaddr *) NULL, NULL);
        while (freepidlock);
        freepidlock = true;
        if (!freepid.empty()) {
            pidind = freepid.front();
            freepid.pop();
            freepidlock = false;
            if (!Send(&ServerReady, 8)) {
                cerr << "Server ERROR\n";
                exit(1);
            }
            break;
        } else {
            freepidlock = false;
            if (!Send(&ServerNoReady, 8)) {
                cerr << "Server ERROR\n";
                exit(1);
            }
        }
    }
    return make_pair(pidind, nfd);
}