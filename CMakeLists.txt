cmake_minimum_required(VERSION 3.16)
project(22s-pa01-kas-and-clayton)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES)

include_directories(src input)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
