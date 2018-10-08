cmake_minimum_required(VERSION 3.12)
project(matriz)

set(CMAKE_CXX_STANDARD 17)

add_executable(matriz src/main.cpp lib/matriz.h src/matriz.cpp)