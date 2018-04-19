cmake_minimum_required(VERSION 3.8)
project(SO2_PR2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/BlocksArena.cpp src/BlocksArena.h src/Block.cpp src/Block.h)
add_executable(SO2_PR2 ${SOURCE_FILES})