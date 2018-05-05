//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>


namespace enp {
    IO::IO() {
        //setsize(databit);
        setsize(1024 - 8);
    }

    IO::IO(string path, ios_base::openmode mode) {
        open(path, mode);
        //setsize(databit);
        setsize(1024 - 8);
        Openmode = mode;
    }

    void IO::open(string p, ios_base::openmode mode) {
        stream.open(path, ios::binary | mode);
    }

    void IO::setsize(uint32_t s) {
        size = s;
    }

    void IO::operator<<(mpz_class data) {
        if (Openmode != ios::out | ios::binary) {
            cerr << "ERROR open mode\n";
            return;
        }
        uint8_t *buf = new uint8_t(size);
        uint8_t i, j;
        for (i = 0; i < size; i++)buf[i] = 0;

        for (i = size - 1; i >= 0; i--) {
            for (j = 0; j < 8; j++) {
                buf[i] <<= 1;
                buf[i] ^ (data % 2);
                data >>= 1;
            }
        }
        for (i = 0; i < size; i++)stream << buf[i];
    }

    uint8_t IO::operator>>(mpz_class &data) {
        if (Openmode != ios::in | ios::binary) {
            cerr << "ERROT open mode\n";
            return 0;
        }
        uint8_t i, j;
        data = 0;
        for (i = 0; i < size; i++){
            if(stream.eof())return i;
            stream>>j;
            data<<=8;
            data+=j;
        }
        return i;
    }
}