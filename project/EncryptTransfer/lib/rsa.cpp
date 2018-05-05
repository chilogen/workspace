//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>
using namespace enp;

RSA::RSA() {}

void RSA::setkey(mpz_class n, mpz_class d) {
    key_n = n;
    key_d = d;
}

bool RSA::setkey(uint8_t i) {
    string path;
    keylen=(int)i*1024;

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
        cerr<<"key file broken,run regenkey";
        genkey();
    }
}

void RSA::genkey() {
    mpz_class p = 1, q = 1, Gcd, a, b;
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
    if (p % 2 == 1)p++;
    if (q % 2 == 1)q++;
    while (!isprime(p))p += 2;
    while (!isprime(q))q += 2;
    key_n = p * q;
    key_phi = (p - 1) * (q - 1);
    i = rand();
    key_e = i;
    while (1) {
        mpz_gcd(Gcd.get_mpz_t(), key_n.get_mpz_t(), key_e.get_mpz_t());
        if (Gcd == 1)break;
        key_e++;
    }
    a = key_phi - 1;
    b = key_n * key_n;
    mpz_powm(key_d.get_mpz_t(), key_e.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
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
    fout<<key_n<<endl<<key_d<<endl<<key_e<<endl<<key_phi;
    fout.close();
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

bool RSA::isprime(mpz_class p) {

    return true;
}

void RSA::readkey(std::string path) {

    ifstream fin(path, ios::in);

    if (!fin.is_open()) {
        cerr << "NO such key file\n";
        exit(1);
    }
    string s1, s2, s3, s4;
    fin >> s1 >> s2 >> s3 >> s4;
    fin.close();
    key_n = s1;
    key_d = s2;
    key_e = s3;
    key_phi = s4;
}

bool RSA::checkkey() {
    bool ans;
    if(!isprime(key_n))return false;
    if(key_e>=key_phi)return false;
    if(key_n%key_e!=1)return false;
    if((key_e*key_d)%key_n!=1)return false;
    return true;
}