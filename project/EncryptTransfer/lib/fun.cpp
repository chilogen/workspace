//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>
using namespace enp;


void socke::set(uint32_t a, uint16_t b) {
    ip=a;
    port=b;
}

sockadd::sockadd() {}

sockadd::sockadd(sockaddr_in a, uint32_t b) {
    this->addr=a;
    this->fd=b;
}

mpz_class enp::x2g(uint8_t* data,uint32_t len){
    uint32_t i,j,k;
    mpz_class ans=0;
    for(i=0;i<len;i++){
        if(data[i]>='0'&&data[i]<='9')k=data[i]-'0';
        else k=data[i]-'A';
        for(j=0;j<4;i++){
            ans*=2;
            if(k&1)ans+=1;
            k=k>>1;
        }
    }
    return ans;
}
pair<uint16_t* ,uint32_t> enp::g2x(mpz_class mp){
    uint32_t len=0,i,j,k;
    mpz_class tmp=mp;
    while (tmp!=0){
        len++;
        tmp/=16;
    }
    uint16_t* data=new uint16_t(len);
    for(i=0;i<len;i++){
        for(j=0,k=0;j<4;j++,k++){
            k=k<<1;
            if(mp%2==1) k^=1;
            mp/=2;
        }
        if(k>=0&&k<=9) data[i]='0'+k;
        else data[i]='A'+k;
    }
    return make_pair(data,len);
}


enp::netparm::netparm(uint32_t a, uint32_t b, uint32_t c, uint8_t *d) {
    this->fd=a;
    this->pidind=b;
    this->bitsize=c;
    this->data=d;
}

enp::funtionparm::funtionparm(uint32_t a, uint32_t b) {
    this->fd=a;
    this->pidind=b;
}