######## SGX SDK Settings ########

SGX_SDK ?= /opt/intel/sgxsdk

SGX_LIBRARY_PATH := $(SGX_SDK)/lib64
SGX_ENCLAVE_SIGNER := $(SGX_SDK)/bin/x64/sgx_sign
SGX_EDGER8R := $(SGX_SDK)/bin/x64/sgx_edger8r

######## App Settings ########

App_Include_Paths := -I$(SGX_SDK)/include 

App_Link_Flags := -L /opt/intel/sgxsdk/lib64 -lsgx_urts -lsgx_ukey_exchange -lsgx_uae_service  -pthread 


.PHONY: all
all: app

######## App Objects ########

enclave_u.c: $(SGX_EDGER8R) enclave.edl
	@$(SGX_EDGER8R) --untrusted enclave.edl --search-path $(SGX_SDK)/include
	@echo "GEN  =>  $@"

enclave_u.o: enclave_u.c
	@$(CC) $(App_Include_Paths) -c $< -o $@
	@echo "CC   <=  $<"

app.o: app.cpp
	@$(CXX) $(App_Include_Paths) -c $< -o $@ 
	@echo "CXX  <=  $<"

app: app.o enclave_u.o
	@$(CXX) $^ -o $@ $(App_Link_Flags)
	@echo "LINK =>  $@"

.PHONY: clean

clean:
	@rm -f *.o app