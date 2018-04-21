add_library(IO io.cpp)
add_library(RSA rsa.cpp)
add_library(NET net.cpp)
add_library(FUN fun.cpp)
add_library(ENP encrypttransfer.cpp)

target_link_libraries(RSA gmpxx gmp ENP)
target_link_libraries(FUN gmpxx gmp)
target_link_libraries(IO gmpxx gmp ENP)