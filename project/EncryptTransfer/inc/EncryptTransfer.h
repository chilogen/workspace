//
// Created by a on 4/12/18.
//

#ifndef ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
#define ENCRYPTTRANSFER_ENCRYPTTRANSFER_H

#define PUBLIC_KEY      0
#define PRIVATE_KEY     1


#include <bits/stdc++.h>
#include <gmpxx.h>

namespace aaa{
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
    const uint16_t ENDFLAG=0xffff;
    const uint16_t DATALEN=256;
    uint32_t codebit=1024;
    std::string key_path="key";
}

#include <io.h>
#include <rsa.h>
#include <client.h>
#include <server.h>

#endif //ENCRYPTTRANSFER_ENCRYPTTRANSFER_H
