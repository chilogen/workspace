cmake_minimum_required(VERSION 3.9)
project(EncryptTransfer)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_subdirectory(lib)

add_executable(recv server.cpp)
add_executable(sendto client.cpp)
target_link_libraries(recv IO ENP NET CODER pthread)
target_link_libraries(sendto IO ENP NET CODER pthread)