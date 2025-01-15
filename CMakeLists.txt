cmake_minimum_required(VERSION 3.10)

project(syfmt)

option(SYFMT_BUILD_TESTS "Build all tests" ON)

include_directories(include)

set(
  SRCS
  src/args.cpp
  src/format.cpp
  src/syfmt.cpp
  src/value.cpp
)

add_library(syfmt ${SRCS})

if(SYFMT_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test/)
endif()
