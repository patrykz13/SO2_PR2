cmake_minimum_required(VERSION 3.8)
project(SO2_PR2)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads)
add_executable(SO2_PR2  src/main.cpp src/Block.h src/Block.cpp src/BlocksArena.h src/BlocksArena.cpp src/InterceptingWindow.h src/InterceptingWindow.cpp
        src/TetrisWindow.h src/TetrisWindow.cpp src/Window.h)
target_link_libraries(SO2_PR2 ncurses ${CMAKE_THREAD_LIBS_INIT})
