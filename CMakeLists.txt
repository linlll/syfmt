cmake_minimum_required(VERSION 3.10)

project(syfmt)

option(SYFMT_BUILD_TESTS "Build all tests" ON)

include_directories(include)

file(GLOB ALL_SRCS src/*.cpp)

add_library(syfmt ${ALL_SRCS})

if(SYFMT_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test/)
endif()
