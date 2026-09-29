cmake_minimum_required(VERSION 4.3)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        IRClientUDP.cpp
        IRClientTCP.cpp
        IRServeurUDP.cpp
        TelloClientUDP.h
        TelloClientUDP.cpp)

if(WIN32)
    target_link_libraries(untitled PRIVATE ws2_32)
endif()
