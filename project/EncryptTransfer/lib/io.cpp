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

    void IO::operator<<(unsigned char *data) {
        if (Openmode != (ios::out | ios::binary)) {
            cerr << "ERROR open mode\n";
            return;
        }

        int i;
        for(i=0;i<size/8;i++)stream.write((char*)&data[i],sizeof(unsigned char));
    }

    uint8_t IO::operator>>(unsigned char* data) {
        if (Openmode != (ios::in | ios::binary)) {
            cerr << "ERROT open mode\n";
            return 0;
        }
        int i;
        for(i=0;i<size/8;i++){
            stream.read((char*)&data[i],sizeof(unsigned char));
            if(stream.eof())return i*8;
        }
        return size;
    }
}