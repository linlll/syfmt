cmake_minimum_required(VERSION 3.10)

project(syfmt)

option(SYFMT_BUILD_TESTS "Build all tests" ON)

include_directories(include)

add_library(syfmt src/format.cpp src/syfmt.cpp)

if(SYFMT_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test/)
endif()
