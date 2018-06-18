/*
 * Created by a on 4/13/18.
 * project head file
 * include all mode declaration
 * project init entity in encrypttransfer.cpp
*/

#define TEST
#define KEYTEST
#define DEBUG



#ifndef ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
#define ENCRYPTTRANSFER_ENCRYPTTRANSFER_H

#define LINUX
//define WINDOWS

#define SERVER  0
#define CLIENT  1

#define PUBLIC_KEY  0
#define PRIVATE_KEY 1
#define ENCRYPT 0
#define DECRYPT 1

#define MAXPID 1000
#define MAXKEYLEN 40960

#include <bits/stdc++.h>
#include <gmpxx.h>
#include <openssl/aes.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

using namespace std;

namespace enp {

    //Header contain transfer data information
    struct Dataheader {
        uint8_t plaintextlen;
        unsigned long long ack;

        void set(uint8_t, unsigned long long);
    };


    //Header contain transfer information
    struct Header{
        char keyn[4096 / 8];
        char keyd[4096 / 8];
        char aeskey[4096/8];
        char filename[4096];
        unsigned long long filesize;
        uint16_t lenkeyn;
        uint16_t lenkeyd;
        uint16_t lenaeskey;
        void ServerSet(mpz_class,mpz_class);
        void ClientSet(mpz_class,char*, unsigned long long);
    };

    //server thread parm
    struct funparm{
        uint32_t pidind;
        uint32_t fd;
        int encodemethod;
        void set(uint32_t,uint32_t,int);
    };


    extern const uint8_t ServerNoReady;         //server not ready to receive data(set constant as 0)
    extern const uint8_t ServerReady;           //server ready to receive data(set constant as 1)
    extern const uint8_t ServerClose;           //server close(set constant as 2)
    extern const uint32_t serverlistenaddr;     //server listen ip(set constant as any)
    extern const uint8_t ENDFLAG;               //mark the transfer is complete(success)(set constant as 0xff) of not
    extern const uint16_t DATALEN;              //data len encry per time(set constant as 127 byte)
    extern const uint16_t FILENAMELEN;          //max filename (len+1),set constatant as 4096


    extern unsigned int ClientSleepTime;        //client sleep time when server not ready
    extern uint32_t serverport;                 //server listen port
    extern pthread_t pid[MAXPID];               //store muti thread pid
    extern queue<uint32_t> freepid;             //max muti pthread control
    extern pthread_mutex_t freepidlock;
    extern bool serverreject;
    extern string k1024;                        //path store 1024 bit key
    extern string k2048;                        //path store 2048 bit key
    extern string k4096;                        //path store 4096 bit key


    mpz_class x2g(unsigned char*, uint16_t);            //encode encrypted data to make easy transfer(replaceable,must match g2x)

    uint16_t g2x(unsigned char *,mpz_class);             //decode encrypted data from transfer to make de-encrypted(replaceable,must match x2g)

    void ctrlc(int sig);                        //handle ctrl-c signal for server

    void clear();                               //different system,different console clear command

}

//mode head file
#include <io.h>
#include <coder.h>
#include <net.h>

#endif //ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
