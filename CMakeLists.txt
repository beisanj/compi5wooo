cmake_minimum_required(VERSION 3.23)
project(compi5woo)

set(CMAKE_CXX_STANDARD 14)

add_executable(compi5woo main.cpp llvmCodeGen.cpp llvmCodeGen.h)
