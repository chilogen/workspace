/*
 * Created by a on 4/13/18.
 * client read file
 * server write file
 * reload operator "<<" for server and ">>" for client
*/

#ifndef ENCRYPTTRANSFER_IO_H
#define ENCRYPTTRANSFER_IO_H

#include <encrypttransfer.h>
namespace enp {
    class IO {
    private:
        uint16_t size;              //data len will read from file next time
        string path;                //file path
        fstream stream;
        _Ios_Openmode Openmode;
    public:
        void operator<<(unsigned char*);

        uint8_t operator>>(unsigned char*);

        void setsize(uint16_t s);

        void open(_Ios_Openmode mode);

        IO();

        IO(char* path, ios_base::openmode mode);

        bool eof() {
            return stream.eof();
        }
    };
}

#endif //ENCRYPTTRANSFER_IO_H
