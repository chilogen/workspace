//
// Created by a on 4/14/18.
//


#include <encrypttransfer.h>
namespace enp {
    uint32_t primebit = 1024;   //max 2048
    uint32_t databit = primebit - 8;
    uint32_t serverport=htons(6666);
    uint32_t serverlistenaddr=htonl(INADDR_ANY);
    std::string key_path = "key";
    const uint16_t ENDFLAG=0xffff;
    const uint16_t DATALEN=256;
    pthread_t pid[10000];
    queue<uint32_t >freepid;
    bool freepidlock=false;
    uint8_t wait=0;
    uint8_t ready=1;
}