#include "enclave_u.h"
#include <sgx_urts.h>
#include <sgx_uae_service.h>
#include <sgx_ukey_exchange.h>
#include <iostream>

using  namespace std;
class testClass {
public:
    sgx_launch_token_t _token = {0};
    sgx_enclave_id_t _eid;
    sgx_ra_context_t _ctx;
    void init_enclave();
    bool request(uint8_t *src, uint32_t srcLen, uint8_t *cmac);

    //will set _ctx here
    //void do_attestation();
}x;


bool testClass::request(uint8_t *src, uint32_t srcLen, uint8_t *cmac) {
    sgx_status_t retval,status;
    status = ecall_calcmac(_eid, &retval,&_ctx, SGX_RA_KEY_SK, src, srcLen, cmac);
    return true;
}

void testClass::init_enclave(){
    sgx_enclave_id_t global_eid;

    sgx_launch_token_t token={0};
    sgx_status_t ret;
    int updated=0;
    ret=sgx_create_enclave("enclave.signed.so",SGX_DEBUG_FLAG, \
							&token,&updated,&global_eid,NULL);

    if(ret!=SGX_SUCCESS){
        std::cout<<"error init enclavedsfdsf\n";
        printf("%08x\n",ret);
        exit(1);
    }

}

int main(){
    x.init_enclave();
    return 0;
}