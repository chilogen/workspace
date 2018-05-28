/*
 * Created by a on 4/13/18.
 * net work init,shake hand
 * offer send and receive data function packaging
*/

#ifndef ENCRYPTTRANSFER_NET_H
#define ENCRYPTTRANSFER_NET_H

#include <encrypttransfer.h>
namespace enp {
    class NET {
    private:
        struct sockaddr_in sock;

        bool check(char *ip, uint32_t port);

    public:
        int fd;
        bool init(char *ip, uint32_t port, int sc);//sc=0-->server   sc=1-->client

        void Connect();//for client
        pair<uint32_t, uint32_t> Listen();//for server

    };


    template <class T>
    bool Send(T* a,int size,uint32_t fd){
        int n;
        void *buf = (void *) a;
        n = write(fd, buf, size);
        if (n != -1) {
            return 1;
        } else return 0;
    }

    template<class T>
    bool Recv(T *a, int size, uint32_t fd) {
        int n;
        void *buf = (void *) a;
        n = read(fd, buf, size);
        if (n ==-1) {
            cerr << "transfer closed\n";
            return 0;
        } else return 1;
    }

}

#endif //ENCRYPTTRANSFER_NET_H
