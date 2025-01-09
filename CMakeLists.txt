cmake_minimum_required(VERSION 3.10)

project(syfmt)

add_library(syfmt format.cpp)

add_executable(format_test format_test.cpp)
target_link_libraries(format_test syfmt)
