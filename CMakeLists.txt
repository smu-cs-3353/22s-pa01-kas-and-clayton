cmake_minimum_required(VERSION 3.16)
project(22s-pa01-kas-and-clayton)

set(CMAKE_CXX_STANDARD 17)
set(src)

set(input01 "Input/sample.txt")
set(input02 "Input/1000Sample.txt")
set(input03 "Input/10000Sample.txt")
set(input04 "Input/100000Sample.txt")

foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

add_executable(22s-pa01-kas-and-clayton src/main.cpp src/Driver.cpp src/Wall.cpp src/Painting.cpp src/Driver.h src/Wall.h src/Painting.h)