/*
 * Created by a on 4/13/18.
 * RSA algorithm use gmp library
*/

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

    public:
        RSA();

        mpz_class encrypt(mpz_class);

        mpz_class decode(mpz_class);

        void setkey(mpz_class, mpz_class);          //client set public key to encrypt

        bool setkey(int i);                         //server set public and private key file path,keylen=i*1024

        bool checkkey();                            //check key read from file is valid

        pair<mpz_class, mpz_class> getpublickey() {
            return make_pair(key_n, key_e);
        };
    };

    class AES{
    private:
        unsigned char key[AES_BLOCK_SIZE];
        AES_KEY aeskey;
        int method;//0-encrypt 1-decrypt
        void readkey(string path);

    public:
        AES(int action):method(action){}
        void genkey();
        void setkey(unsigned char *);
        void getkey(unsigned char *);
        void encrypt(unsigned char* in, unsigned char *out);
        void decrypt(unsigned char *in, unsigned char *out);
    };
}


#endif //ENCRYPTTRANSFER_RSA_H
