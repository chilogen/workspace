//
// Created by a on 4/13/18.
//

#ifndef ENCRYPTTRANSFER_RSA_H
#define ENCRYPTTRANSFER_RSA_H

#include <encrypttransfer.h>

namespace enp{
    class RSA{
    private:
        mpz_class key_n,key_phi,key_e,key_d;
        int32_t readkey(string path,int32_t flag);
        void genkey();
        bool isprime(mpz_class p);
    public:
        RSA(string path,int32_t flag);
        RSA();
        vector<mpz_class>encrypt(vector<mpz_class>);
        vector<mpz_class>decode(vector<mpz_class>);
        void setpkey(mpz_class,mpz_class);
    };
}

#endif //ENCRYPTTRANSFER_RSA_H
