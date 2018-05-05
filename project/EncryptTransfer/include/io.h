//
// Created by a on 4/13/18.
//

#ifndef ENCRYPTTRANSFER_IO_H
#define ENCRYPTTRANSFER_IO_H

#include <encrypttransfer.h>
namespace enp {
    class IO {
    private:
        uint8_t size;
        string path;
        fstream stream;
        ios_base::openmode Openmode;
    public:
        void operator<<(mpz_class data);

        uint8_t operator>>(mpz_class &data);

        void setsize(uint32_t s);

        void open(string p, ios_base::openmode mode);

        IO();

        IO(string path, ios_base::openmode mode);

        bool eof() {
            return stream.eof();
        }
    };
}

#endif //ENCRYPTTRANSFER_IO_H
