//
// Created by a on 4/14/18.
//


#include <encrypttransfer.h>
namespace enp {
    uint32_t primebit = 1024;
    uint32_t databit = primebit - 8;
    std::string key_path = "key";
    const uint16_t ENDFLAG=0xffff;
    const uint16_t DATALEN=256;
}