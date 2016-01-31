cmake_minimum_required(VERSION 3.3)
project(util)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp merge.cpp merge.h)
add_executable(util ${SOURCE_FILES})