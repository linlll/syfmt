cmake_minimum_required(VERSION 3.10)

project(syfmt)

option(BUILD_TESTS "Build all tests" ON)

include_directories(include)

add_library(syfmt src/format.cpp)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(test/)
endif()
