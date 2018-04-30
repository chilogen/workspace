//
// Created by a on 4/13/18.
//

#include <encrypttransfer.h>
using namespace enp;

RSA::RSA() {
    genkey();
}

RSA::RSA(string path, int32_t flag) {
    readkey(path,flag);
}

void RSA::setpkey(mpz_class n,mpz_class d){
    key_n=n;
    key_d=d;
}

void RSA::genkey() {
    mpz_class p=1,q=1,Gcd,a,b;
    uint32_t i,j;
    srand((unsigned)time(NULL));
    //for(i=1;i<primebit;i++){
    for(i=1;i<1024;i++){
        p*=2;q*=2;
        j=rand()%2;
        if(j)p++;
        j=rand()%2;
        if(j)q++;
    }
    if(p%2==1)p++;if(q%2==1)q++;
    while(!isprime(p))p+=2;
    while(!isprime(q))q+=2;
    key_n=p*q;
    key_phi=(p-1)*(q-1);
    i=rand();
    key_e=i;
    while(1){
        mpz_gcd(Gcd.get_mpz_t(),key_n.get_mpz_t(),key_e.get_mpz_t());
        if(Gcd==1)break;
        key_e++;
    }
    a=key_phi-1; b=key_n*key_n;
    mpz_powm(key_d.get_mpz_t(),key_e.get_mpz_t(),a.get_mpz_t(),b.get_mpz_t());
}

vector<mpz_class> RSA::encrypt(vector<mpz_class>cleartext) {
    vector<mpz_class>cipertext;
    uint32_t size=cleartext.size(),i;
    mpz_class res;
    for(i=0;i<size;i++){
        mpz_powm(res.get_mpz_t(),cleartext[i].get_mpz_t(),key_e.get_mpz_t(),key_n.get_mpz_t());
        cipertext.push_back(res);
    }
    return cipertext;
}

vector<mpz_class> RSA::decode(vector<mpz_class> cipertext) {
    vector<mpz_class> cleartext;
    uint32_t size=cipertext.size(),i;
    mpz_class res;
    for(i=0;i<size;i++){
        mpz_powm(res.get_mpz_t(),cipertext[i].get_mpz_t(),key_d.get_mpz_t(),key_n.get_mpz_t());
        cleartext.push_back(res);
    }
    return cleartext;
}

bool RSA::isprime(mpz_class p) {

    return true;
}

int32_t RSA::readkey(string path, int32_t flag) {

}