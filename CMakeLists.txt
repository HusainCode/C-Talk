cmake_minimum_required(VERSION 3.21)
project(C_Talk C)

set(CMAKE_C_STANDARD 11)
add_executable(C_Talk main.c chat_protocol.c
        server.c)
target_link_libraries(C_Talk Ws2_32)
