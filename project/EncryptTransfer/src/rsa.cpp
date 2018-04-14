//
// Created by a on 4/12/18.
//

#include <EncryptTransfer.h>

namespace aaa{
    RSA::RSA() {}
    RSA::~RSA() {}
    void RSA::encrypt() {}
    void RSA::decode() {}
    void RSA::push(int8_t v[DATALEN/8]){
        int32_t len=DATALEN/16,i;
        int16_t *c;
        char tmp;
        for(i=0;i<len;i++){
            c=(int16_t *)&v[i*16];
            tmp=char(*c);
            buffer+=tmp;
            if(buffer.length()==1024/4){
                x2mp();
                buffer="";
            }
        }
    }
    void RSA::x2mp() {
        int32_t i,j,l=buffer.length()-1;
        mpz_class k=0;
        for(i=l;i>=0;i--){
            k=k<<4;
            if(buffer[i]>='0'&&buffer[i]<='9')j=buffer[i]-'1';
            else j=buffer[i]-'A'+10;
            k=k^j;
        }
        data.push_back(k);
    }
    void RSA::genkey(int bit) {
        mpz_class a,b;
        key_p=key_q=1;
        int32_t i,j;
        uint32_t k;
        srand((unsigned)time(NULL));
        for(i=1;i<bit;i++){
            key_p=key_p<<1;
            key_q=key_q<<1;
            j=rand()%2;
            key_p=key_p^1;
            j=j%2;
            key_q=key_q^1;
        }
        if(key_q%2==1)key_q++;
        if(key_p%2==1)key_p++;
        while(!isprime(key_p))key_p+=2;
        while(!isprime(key_q))key_q+=2;
        key_n=key_q*key_p;
        key_phi=(key_p-1)*(key_q-1);
        k=(unsigned int32_t)rand();
        key_e=k;
        while(key_phi%key_e==0)key_e++;
        a=key_phi-2;b=key_n*key_n;
        mpz_powm(key_d.get_mpz_t(),key_e.get_mpz_t(),a.get_mpz_t(),b.get_mpz_t());
    }
    bool RSA::isprime(mpz_class p) {
        return mpz_probab_prime_p(p.get_mpz_t(),10)==2;
    }
}