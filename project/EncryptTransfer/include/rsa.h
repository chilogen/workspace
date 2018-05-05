//
// Created by a on 4/13/18.
//

#ifndef ENCRYPTTRANSFER_RSA_H
#define ENCRYPTTRANSFER_RSA_H

#include <encrypttransfer.h>

namespace enp {
    class RSA {
    private:
        mpz_class key_n, key_phi, key_e, key_d;
        int keylen;

        void genkey();

        void readkey(string);

        bool isprime(mpz_class p);

    public:
        RSA();

        mpz_class encrypt(mpz_class);

        mpz_class decode(mpz_class);

        void setkey(mpz_class, mpz_class);

        bool setkey(uint8_t);

        bool checkkey();

        pair<mpz_class, mpz_class> getpublickey() {
            return make_pair(key_n, key_d);
        };
    };
}

#endif //ENCRYPTTRANSFER_RSA_H
