//
// Created by a on 4/13/18.
//

#define TEST
#define KEYTEST
//#define DEBUG



#ifndef ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
#define ENCRYPTTRANSFER_ENCRYPTTRANSFER_H

#define LINUX
//define WINDOWS

#define SERVER  0
#define CLIENT  1

#define PUBLIC_KEY  0
#define PRIVATE_KEY 1

#define MAXPID 1000
#define MAXKEYLEN 40960

#include <bits/stdc++.h>
#include <gmpxx.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

namespace enp {
    struct Dataheader {
        uint16_t ciphertextlen;
        uint8_t plaintextlen;
        uint8_t end;

        void set(uint16_t, uint8_t, uint8_t);
    };


    struct Header{
        char keyn[4096 / 8];
        char keyd[4096 / 8];
        uint16_t lenkeyn;
        uint16_t lenkeyd;
        void set(mpz_class,mpz_class);
    };

    struct funparm{
        uint32_t pidind;
        uint32_t fd;
        int encodemethod;
        void set(uint32_t,uint32_t,int);
    };


    extern uint8_t ServerNoReady;
    extern uint8_t ServerReady;
    extern unsigned int ClientSleepTime;
    extern const uint8_t ENDFLAG;
    extern const uint16_t DATALEN;
    extern uint32_t serverport;
    extern uint32_t serverlistenaddr;
    extern pthread_t pid[MAXPID];
    extern queue<uint32_t> freepid;
    extern bool freepidlock;
    extern string k1024;
    extern string k2048;
    extern string k4096;


    mpz_class x2g(string, uint16_t);

    uint16_t g2x(char *,mpz_class);

    void clear();

}

#include <io.h>
#include <rsa.h>
#include <net.h>

#endif //ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
