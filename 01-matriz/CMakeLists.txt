cmake_minimum_required(VERSION 3.12)
project(matriz)

set(CMAKE_CXX_STANDARD 17)

add_executable(matriz main.cpp lib/matriz.h matriz.cpp)