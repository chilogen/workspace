//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>
using namespace enp;





RSA::RSA() {}

void RSA::setkey(mpz_class n, mpz_class d) {
    key_n = n;
    key_e = d;
}

bool RSA::setkey(int i) {
    string path;
    keylen=i*1024;

    pair<mpz_class,mpz_class>p;
    switch(keylen){
        case 1024:{
            path=k1024;
            break;
        }
        case 2048:{
            path=k2048;
            break;
        }
        case 4096:{
            path=k4096;
            break;
        }
    }
    readkey(path);
    if(!checkkey()){
        //cerr<<"key file broken,run regenkey\n";
        genkey();
    }
}

void RSA::genkey() {
    mpz_class p = 1, q = 1, Gcd;
    uint32_t i, j;
    srand((unsigned) time(NULL));
    for (i = 0; i <keylen>>1; i++) {//i from 0 to keylen/2,make p&q one more bit and n two more bits
        p *= 2;
        q *= 2;
        j = rand() % 2;
        if (j)p++;
        j = rand() % 2;
        if (j)q++;
    }

    mpz_class tmp1=p,tmp2=q;
    mpz_nextprime(p.get_mpz_t(),tmp1.get_mpz_t());
    mpz_nextprime(q.get_mpz_t(),tmp2.get_mpz_t());


    key_n = p * q;
    key_phi = (p - 1) * (q - 1);
    key_e=65537;

    mpz_invert(key_d.get_mpz_t(),key_e.get_mpz_t(),key_phi.get_mpz_t());

    string path;
    switch(keylen){
        case 1024:{
            path=k1024;
            break;
        }
        case 2048:{
            path=k2048;
            break;
        }
        case 4096:{
            path=k4096;
            break;
        }
    }
    ofstream fout(path,ios::out);
    fout<<key_n<<endl<<endl<<key_d<<endl<<endl<<key_e<<endl<<endl<<key_phi;
    fout.close();
#ifdef KEY_TEST
    exit(1);
#endif
}

mpz_class RSA::encrypt(mpz_class plainttext) {
    mpz_class ciphertext;
    mpz_powm(ciphertext.get_mpz_t(), plainttext.get_mpz_t(), key_e.get_mpz_t(), key_n.get_mpz_t());
    return ciphertext;
}
mpz_class RSA::decode(mpz_class ciphertext) {
    mpz_class plainttext;
    mpz_powm(plainttext.get_mpz_t(), ciphertext.get_mpz_t(), key_d.get_mpz_t(), key_n.get_mpz_t());
    return plainttext;
}


void RSA::readkey(std::string path) {

    ifstream fin(path, ios::in);

    if (!fin.is_open()) {
        cerr << "NO such key file\n";
        cerr<<"run regenkey\n";
        genkey();
    }
    fin >> key_n >> key_d >> key_e >> key_phi;
    fin.close();
}

bool RSA::checkkey() {
    int i=0;
    mpz_class tmp=key_n;
    while(tmp){
        i++;
        tmp>>=1;
    }
    if(i!=keylen+2)return false;
    if(key_e>key_phi)return false;
    tmp=key_e*key_d;
    if((key_e*key_d)%key_n!=1)return false;
    mpz_gcd(tmp.get_mpz_t(),key_e.get_mpz_t(),key_n.get_mpz_t());
    if(tmp!=1)return false;
    return true;
}

void AES::genkey() {
    unsigned char k[AES_BLOCK_SIZE];
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<16;i++)k[i]=rand()%256;
    memcpy(key,k,sizeof(key));
    AES_KEY tk;
    if(method==ENCRYPT)AES_set_encrypt_key(k,128,&tk);
    if(method==DECRYPT)AES_set_decrypt_key(k,128,&tk);
    aeskey=tk;
}

void AES::setkey(unsigned char * k) {
    memcpy(key,k,sizeof(key));
    AES_KEY tk;
    if(method==ENCRYPT)AES_set_encrypt_key(k,128,&tk);
    if(method==DECRYPT)AES_set_decrypt_key(k,128,&tk);
    aeskey=tk;
}

void AES::readkey(string path) {
    ifstream fin(path, ios::in);

    if (!fin.is_open()) {
        cerr << "NO such key file\n";
        cerr<<"run regenkey\n";
        genkey();
    }
    unsigned char k[AES_BLOCK_SIZE];
    fin >> k;
    memcpy(key,k,sizeof(key));
    fin.close();

}

void AES::getkey(unsigned char *tkey) {
    memcpy(tkey,key,sizeof(unsigned char)*AES_BLOCK_SIZE);
}

void AES::encrypt(unsigned char *in, unsigned char *out) {
    AES_KEY tk=aeskey;
    AES_encrypt(in,out,&tk);
}

void AES::decrypt(unsigned char *in, unsigned char *out) {
    AES_KEY tk=aeskey;
    AES_decrypt(in,out,&tk);
}