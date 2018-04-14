//
// Created by a on 4/12/18.
//

#ifndef ENCRYPTTRANSFER_RSA_H
#define ENCRYPTTRANSFER_RSA_H

#include <EncryptTransfer.h>

namespace aaa{
    class RSA{
    public:
        void encrypt();
        void decode();
        void push(int8_t v[DATALEN/8]);
        void genkey(int bit=512);
        vector<mpz_class>data;
        RSA();
        ~RSA();

    private:
        std::string buffer;
        mpz_class key_n,key_e,key_d,key_p,key_q,key_phi;
        void x2mp();
        bool isprime(mpz_class p);
    };
}


#endif //ENCRYPTTRANSFER_RSA_H
