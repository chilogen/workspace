cmake_minimum_required(VERSION 3.9)
project(EncryptTransfer)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_subdirectory(lib)
add_executable(server server.cpp)
add_executable(client client.cpp)
target_link_libraries(server IO FUN NET RSA pthread)
target_link_libraries(client IO FUN NET RSA)