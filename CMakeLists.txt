cmake_minimum_required(VERSION 3.8)
project(SO2_PR2)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)
set(SOURCE_FILES src/main.cpp src/BlocksArena.cpp src/BlocksArena.h src/TetrisWindow.cpp src/TetrisWindow.h src/InterceptingWindow.cpp src/InterceptingWindow.h src/Block.cpp src/Block.h src/Window.h src/Window.cpp)
add_executable(SO2_PR2 ${SOURCE_FILES})
target_link_libraries(SO2_PR2 ncurses ${CMAKE_THREAD_LIBS_INIT})
