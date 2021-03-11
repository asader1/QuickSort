cmake_minimum_required(VERSION 3.17)
project(Quicksort_Lab_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Quicksort_Lab_master
        main-test.cpp
        main.cpp
        QS.cpp
        QSInterface.h)
