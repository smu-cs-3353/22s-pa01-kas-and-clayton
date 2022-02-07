cmake_minimum_required(VERSION 3.16)
project(22s-pa01-kas-and-clayton)

set(CMAKE_CXX_STANDARD 17)
set(src)

include_directories(src)

#add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Driver.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/src/Painting.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Wall.cpp)

add_executable(22s-pa01-kas-and-clayton src/main.cpp src/Driver.cpp src/Wall.cpp src/Painting.cpp)
