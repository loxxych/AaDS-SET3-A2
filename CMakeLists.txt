cmake_minimum_required(VERSION 4.0)
project(SET3_A2)

set(CMAKE_CXX_STANDARD 20)

add_executable(SET3_A2 test.cpp
        SortTester/SortTester.cpp
        SortTester/SortTester.h
        ArrayGenerator/ArrayGenerator.cpp
        ArrayGenerator/ArrayGenerator.h
        Sorter/Sorter.cpp
        Sorter/Sorter.h)
