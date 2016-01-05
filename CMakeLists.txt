project(asm_interpreter CXX)

## CMAKE VERSION
cmake_minimum_required(VERSION 2.6)

## SETTING UP COMPILER AND LINKER FLAGS
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated-declarations")
set(CMAKE_CXX_COMPILER "g++")

## COMPILE
add_executable(asm src/main.cpp)
