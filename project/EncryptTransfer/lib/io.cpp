//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>


namespace enp {
    IO::IO() {
        //setsize(databit);
        setsize(127);
    }

    IO::IO(char* path, _Ios_Openmode mode) {
        stream.open(path, mode);
        //setsize(databit);
        setsize(127);
        Openmode = mode;
    }

    void IO::open(string p, ios_base::openmode mode) {
        //stupid error
        //stream.open(path, ios::binary | mode);
        stream.open(path,mode);
    }

    void IO::setsize(uint32_t s) {
        size = s;
    }

    void IO::operator<<(mpz_class data) {
        if (Openmode != (ios::out | ios::binary)) {
            cerr << "ERROR open mode\n";
            return;
        }

        //temporary
        char buf[512];

        int i;
        unsigned long k;
        for (i = 0; i < size; i++)buf[i] = 0;
        mpz_class tmp;

        for (i = size-1; i >= 0; i--) {
            tmp=data%256;
            k=mpz_get_ui(tmp.get_mpz_t());
            data>>=8;
            buf[i]=k;
        }
        for (i = 0; i < size; i++)//stream << buf[i];
            stream.write(&buf[i],sizeof(char));
    }

    uint8_t IO::operator>>(mpz_class &data) {
        if (Openmode != (ios::in | ios::binary)) {
            cerr << "ERROT open mode\n";
            return 0;
        }
        uint8_t i;
        char j;
        data = 0;
        for (i = 0; i < size; i++){
            //stream>>j;
            stream.read(&j,sizeof(j));
            if(stream.eof())return i;
            data<<=8;
            data+=j;
        }
        return size;
    }
}