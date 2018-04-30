//
// Created by a on 4/13/18.
//

#ifndef ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
#define ENCRYPTTRANSFER_ENCRYPTTRANSFER_H

#include <bits/stdc++.h>
#include <gmpxx.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

namespace enp{
    struct socke{
        uint32_t ip;
        uint16_t port;
        void set(uint32_t a,uint16_t b);
    };
    struct sockadd{
        sockaddr_in addr;
        uint32_t fd;
        sockadd();
        sockadd(sockaddr_in a,uint32_t b);
    };
    struct netparm{
        uint32_t fd;
        uint32_t pidind;
        uint32_t bitsize;
        uint8_t * data;
        netparm(uint32_t,uint32_t,uint32_t,uint8_t *);
    };
    struct Header{
        uint16_t filename[4096+1];
        uint32_t ipaddr;
        uint32_t port;
        uint8_t key[4096/8];
    };
    struct TransferHeader{
        uint8_t offset;
        uint8_t size;
    };
    struct funtionparm{
        uint32_t fd;
        uint32_t pidind;
        funtionparm(uint32_t,uint32_t=0);
    };

    extern const uint16_t ENDFLAG;
    extern const uint16_t DATALEN;
    extern uint32_t primebit;
    extern uint32_t databit;
    extern std::string key_path;
    extern uint32_t serverport;
    extern uint32_t serverlistenaddr;
    extern pthread_t pid[10000];
    extern queue<uint32_t >freepid;
    extern bool freepidlock;
    extern uint8_t wait;
    extern uint8_t ready;

    mpz_class x2g(uint8_t* data,uint32_t len);
    pair<uint16_t* ,uint32_t> g2x(mpz_class mp);
}

#include <io.h>
#include <rsa.h>
#include <net.h>

#endif //ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
