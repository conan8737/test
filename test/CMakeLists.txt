cmake_minimum_required(VERSION 2.9)
project(test_main)

set(CMAKE_CXX_FLAGS "-g -O2 -Wall")

include_directories(../core)
link_directories(../core)

file(GLOB SRC "../core/*.cpp")

add_executable(exe/test_timer_heap test_timer_heap.cpp ${SRC})