//
// Created by a on 4/13/18.
//

#ifndef ENCRYPTTRANSFER_NET_H
#define ENCRYPTTRANSFER_NET_H

#include <encrypttransfer.h>
namespace enp{
    class NET{
    public:
        sockadd connect(socke);
        uint32_t listen(uint32_t);
        uint32_t recv(netparm);
        uint32_t send(netparm);
    };
}

#endif //ENCRYPTTRANSFER_NET_H
