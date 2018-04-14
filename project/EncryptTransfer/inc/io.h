//
// Created by a on 4/12/18.
//

#ifndef ENCRYPTTRANSFER_IO_H
#define ENCRYPTTRANSFER_IO_H

#include <EncryptTransfer.h>
using namespace std;

namespace aaa {
    int32_t check(string &key);

    int32_t readkey(string path, mpz_class &ans);

    int32_t readdata(string path, mpz_class *&data, int64_t &len);

    int32_t getkey(int32_t flag, mpz_class &key);

    class IO{
    public:
        void operator<<()
    };
}
#endif //ENCRYPTTRANSFER_IO_H
