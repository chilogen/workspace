add_library(IO io.cpp)
add_library(CODER coder.cpp)
add_library(NET net.cpp)
add_library(ENP encrypttransfer.cpp)

target_link_libraries(CODER ssl crypto gmpxx gmp ENP)
target_link_libraries(IO gmpxx gmp ENP)