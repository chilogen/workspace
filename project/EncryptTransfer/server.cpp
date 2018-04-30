//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>

using namespace enp;

NET Server;

void* serverfun(void *args) {
    signal(SIGPIPE,SIG_IGN);
    uint32_t fd=((funtionparm*)args)->fd;
    uint32_t pidind=((funtionparm*)args)->pidind;
    uint8_t buffer[5000];

    char filename[513];
    RSA coder;

    //get filename  part1
    if(!Server.recv(*(new netparm(fd,pidind,(uint32_t)512,buffer)))){
        cerr<<"transfer closed\n";
        return (void*)NULL;
    }
    else {
        memset(filename,0,sizeof(filename));
        memcpy(filename,buffer,512);
    }

    IO fout(filename,ios::out|ios::binary);

    //get public key part1
    if(!Server.recv(*(new netparm(fd,pidind,(uint32_t)512,buffer)))){
        cerr<<"transfer closed\n";
        return (void*)NULL;
    }
    else coder.setpkey(x2g(buffer,2048),x2g(buffer+2048,2048));

    TransferHeader *header=(TransferHeader *)buffer;
    while(1){
        if(!Server.recv(*(new netparm(fd,pidind,(uint32_t)2,buffer)))){
            cerr<<"transfer closed\n";
            return (void*)NULL;
        }
        else if(*((uint16_t*)buffer)==ENDFLAG){
            cout<<"Transfer compelete.\n";
            break;
        }
        else{
            for(int i=0;i<header->size;i++){
                uint8_t tmpbuffer[5000];
                if(!Server.recv(*(new netparm(fd,pidind,(uint32_t)32,tmpbuffer)))){
                    cerr<<"transfer closed\n";
                    return (void*)NULL;
                }
                else fout<<x2g(tmpbuffer,(256*header->size+header->offset)/8);
            }
        }
    }
    close(fd);
    while(freepidlock);
    freepidlock=true;
    freepid.push(pidind);
    freepidlock=false;
}

int main(){
    sockadd ServerAddres;
    socke ServerlistenSocket;
    ServerlistenSocket.set(serverlistenaddr,serverport);
    ServerAddres=Server.connect(ServerlistenSocket);
    listen(ServerAddres.fd,20);
    cout<<"server ready for transfer data...\n";
    while(1){
        uint32_t fd=Server.listen(ServerAddres.fd);
        while(freepidlock);
        freepidlock=true;
        if(freepid.empty()){
            write(fd,&wait,1);
            freepidlock=false;
            continue;
        }
        uint32_t j;
        j=freepid.front();freepid.pop();
        freepidlock=false;
        pthread_create(&pid[j],NULL,serverfun,(void*)new funtionparm(fd,j));
    }

    return 0;
}