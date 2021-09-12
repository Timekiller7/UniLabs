cmake_minimum_required(VERSION 3.20)
project(2)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(2 main.cpp
        one.cpp
        one.h
        two.cpp
        two.h thr.cpp thr.h)
