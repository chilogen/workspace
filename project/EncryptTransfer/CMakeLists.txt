cmake_minimum_required(VERSION 3.9)
project(EncryptTransfer)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc)
add_subdirectory(src)
add_executable(server src/enpserver.cpp)
add_executable(client src/enpclient.cpp)
target_link_libraries(server RSA)
target_link_libraries(client RSA)