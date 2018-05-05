//
// Created by a on 4/13/18.
//

#ifndef ENCRYPTTRANSFER_NET_H
#define ENCRYPTTRANSFER_NET_H

#include <encrypttransfer.h>
namespace enp {
    class NET {
    private:
        struct sockaddr_in sock;
        uint32_t fd;

        bool check(char *ip, uint32_t port);

    public:
        bool init(char *ip, uint32_t port, int sc);//sc=0-->server   sc=1-->client
        void Connect(Header H);

        pair<uint32_t, uint32_t> Listen();

        template<class T>
        bool Recv(T *&buf, int size);

        template<class T>
        bool Send(T *buf, int size);
    };

    template<class T>
    bool Recv(T *&buf, int size, uint32_t pidind, uint32_t fd);


    template<class T>
    bool NET::Send(T *a, int size) {
        int n;
        void *buf = (void *) a;
        n = write(fd, buf, size);
        if (n != size) {
            close(fd);
            return 0;
        } else return 1;
    }

    template<class T>
    bool NET::Recv(T *&a, int size) {
        int n;
        void *buf = (void *) a;
        n = read(fd, buf, size);
        if (n != size) {
            close(fd);
            return 0;
        } else return 1;
    }

    template<class T>
    bool Recv(T *&a, int size, uint32_t pidind, uint32_t fd) {
        int n;
        void *buf = (void *) a;
        n = read(fd, buf, size);
        if (n != size) {
            close(fd);
            while (freepidlock);
            freepidlock = true;
            freepid.push(pidind);
            freepidlock = false;
            cerr << "transfer closed\n";
            return 0;
        } else return 1;
    }

}

#endif //ENCRYPTTRANSFER_NET_H
