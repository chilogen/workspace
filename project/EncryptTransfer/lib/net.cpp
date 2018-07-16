//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>

using namespace enp;

bool NET::check(char *ip, uint32_t port) {
    uint32_t p = 0;;
    uint8_t buf[sizeof(struct in6_addr)];
    if (!inet_pton(AF_INET, ip, buf))return 0;
    if (port <= 1024 || port > 65535)return 0;
    return 1;
}

bool NET::init(char *ip, uint32_t port, int sc) {
    if (sc == CLIENT && !this->check(ip, port)) {
        cerr << "wrong IP or PORT\n";
        return 0;
    }

    fd = socket(AF_INET, SOCK_STREAM, 0);


    memset(&sock, 0, sizeof(sock));
    sock.sin_family = AF_INET;
    sock.sin_port = port;

    switch (sc) {
        case SERVER: {
            unsigned int i;
            pthread_mutex_lock(&freepidlock);
            for(i=0;i<MAXPID;i++)freepid.push(i);
            pthread_mutex_unlock(&freepidlock);
            sock.sin_addr.s_addr = serverlistenaddr;
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

void NET::Connect() {
    uint8_t handshake = ServerNoReady;

    while (1) {
        connect(fd, (struct sockaddr *) &sock, sizeof(sock));
        void *tmp = (void *) &handshake;
        if (!Recv(tmp, 1, fd)) {
            cerr << "Server ERROR\n";
            exit(1);
        }
        if (handshake == ServerNoReady) {
            close(fd);
            sleep(ClientSleepTime);
        } else break;
    }
}

pair<uint32_t,uint32_t > NET::Listen() {
    uint32_t nfd, pidind;
    if(serverreject&&!Send(&ServerNoReady,1,nfd)){
        cerr << "Server ERROR\n";
        exit(1);
    }
    while (true) {
        nfd = accept(fd, (struct sockaddr *) NULL, NULL);
        if(serverreject){
            if(!Send(&ServerClose,1,nfd)){
                close(nfd);
                cerr << "Server ERROR\n";
                exit(1);
            }
            close(nfd);
            break;
        }
        pthread_mutex_lock(&freepidlock);
        if (!freepid.empty()) {
            pidind = freepid.front();
            freepid.pop();
            pthread_mutex_unlock(&freepidlock);
            if(!Send(&ServerReady,1,nfd)){
                close(nfd);
                cerr << "Server ERROR\n";
                exit(1);
            }
            cout<<"build a connection\n";
            break;
        } else {
            pthread_mutex_unlock(&freepidlock);
            if(!Send(&ServerNoReady,1,nfd)){
                close(nfd);
                cerr << "Server ERROR\n";
                exit(1);
            }
        }
    }
    return make_pair(pidind, nfd);
}