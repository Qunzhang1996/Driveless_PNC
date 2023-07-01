cmake_minimum_required(VERSION 3.0)
project(SOLDER)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(my_cmake_exe main.cpp src/Solder.cpp src/Gun.cpp)