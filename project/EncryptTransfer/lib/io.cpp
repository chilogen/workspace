//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>


namespace enp{
    IO::IO() {
        //setsize(databit);
        setsize(1024-8);
    }

    IO::IO(string path,ios_base::openmode mode) {
        open(path,mode);
        //setsize(databit);
        setsize(1024-8);
        openmode=mode;
    }

    void IO::open(string p,ios_base::openmode mode) {
        stream.open(path,ios::binary|mode);
    }

    void IO::setsize(uint32_t s) {
        size=s;
    }

    void IO::operator<<(mpz_class data) {
        if(openmode!=ios::in){
            cerr<<"ERROR open mode\n";
            return ;
        }
        uint32_t i,j;
        uint16_t k;
        j=0xff;
        mpz_class allone=j,tmp;

        for(i=size-8;i>=0;i-=8){
            tmp=data>>i;
            tmp=tmp&allone;
            k=(uint16_t)mpz_get_ui(tmp.get_mpz_t());
            stream<<k;
        }
    }

    void IO::operator>>(mpz_class &data) {
        if(openmode!=ios::out){
            cerr<<"ERROT open mode\n";
            return ;
        }
        uint32_t i,j;
        uint16_t k;
        data=0;
        for(i=0;i<size/8;i++){
            data<<=8;
            stream>>k;
            data+=k;
        }
    }
}