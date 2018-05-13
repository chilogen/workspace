//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>


namespace enp {
    IO::IO() {
        //setsize(databit);
        setsize(DATALEN);
    }

    IO::IO(char* p, _Ios_Openmode mode) {
        path=p;
        open(mode);
        //setsize(databit);
        setsize(DATALEN);
        Openmode = mode;
    }

    void IO::open(_Ios_Openmode mode) {
        //stupid error,mode already set as binary last layout
        //stream.open(path, ios::binary | mode);
        stream.open(path,mode);
        if(!stream.is_open()){
            cerr<<"file open error\n";
            exit(1);
        }
    }

    void IO::setsize(uint16_t s) {
        size = s;
    }

    void IO::operator<<(mpz_class data) {
        if (Openmode != (ios::out | ios::binary)) {
            cerr << "ERROR open mode\n";
            return;
        }

        char buf[1024];

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
        unsigned char j;
        //error: char j;
        data = 0;
        for (i = 0; i < size; i++){
            //stream>>j;
            stream.read((char*)&j,sizeof(j));
            if(stream.eof())return i;
            data<<=8;
            data+=j;
        }
        return size;
    }
}