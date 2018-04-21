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
        uint32_t bitsize;
        uint16_t* data;
    };
    struct Header{
        uint16_t filename[4096+1];
        uint32_t ipaddr;
        uint32_t port;
        uint8_t key[4096/8];
    };
    struct TranHeader{
        uint8_t offset;
        uint8_t size;
    };
    struct END{
        uint16_t flag;
    };

    extern const uint16_t ENDFLAG;
    extern const uint16_t DATALEN;
    extern uint32_t primebit;
    extern uint32_t databit;
    extern std::string key_path;

    mpz_class x2g(uint16_t* data,uint32_t len);
    pair<uint16_t* ,uint32_t> g2x(mpz_class mp);
    void *netrecvfun(void* args);
}

#include <io.h>
#include <rsa.h>
#include <net.h>

#endif //ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
