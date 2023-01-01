# /**
# * @file CMakeLists.txt
# * @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
# * @brief Top level cmakelists
# * @version 0.1
# * @date 2023-07-29
# * 
# * @copyright Copyright (c) 2023
# * 
# */

#minimum cmake version required
cmake_minimum_required(VERSION 3.21)

#project name
project(GoogleMockWithEmbeddedC)

#compiler flags for gcov/gcovr coverage analyzis
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

#compiler flags for C standard 
set(CMAKE_C_STANDARD 14)

# Set the source directory to the current directory
set(CMAKE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

# Specify the desired build directory
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

#include test subdirectories
add_subdirectory(test)
add_subdirectory(test/googletest)
