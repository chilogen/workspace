include_directories (/opt/intel/sgxsdk/include)

link_directories (/opt/intel/sgxsdk/lib64)

add_library (enclave_untrusted enclave_u.c)

add_executable (app app.cpp)

target_link_libraries (app enclave_untrusted sgx_ukey_exchange sgx_urts sgx_uae_service pthread)