//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>

using namespace enp;



sockadd NET::connect(socke soc) {
    struct sockaddr_in serveraddr;
    uint32_t fd;
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=soc.ip;
    serveraddr.sin_port=soc.port;
    fd=socket(AF_INET,SOCK_STREAM,0);
    bind(fd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    sockadd ans(serveraddr,fd);
    return ans;
}

uint32_t NET::listen(uint32_t fd) {
    return accept(fd,(struct sockaddr*)NULL,NULL);
}

uint32_t NET::recv(netparm parm) {
    uint8_t *buff=parm.data;
    uint32_t len=parm.bitsize;
    uint32_t fd=parm.fd;
    uint32_t pidind=parm.pidind;
    if(read(fd,buff,len)==0){
        while(freepidlock);
        freepidlock=true;
        freepid.push(pidind);
        freepidlock=false;
        close(fd);
        return 0;
    }
    else return 1;
}

uint32_t NET::send(netparm parm) {
    uint8_t * buff=parm.data;
    uint32_t len=parm.bitsize;
    uint32_t fd=parm.fd;
    return write(fd,buff,len);
}