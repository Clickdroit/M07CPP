cmake_minimum_required(VERSION 4.3)
project(ServeurUDP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ServeurUDP main.cpp IRServeurUDP.cpp IRServeurUDP.h)

if(WIN32)
    target_link_libraries(ServeurUDP PRIVATE ws2_32)
endif()
