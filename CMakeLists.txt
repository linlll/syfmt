cmake_minimum_required(VERSION 3.10)

project(syfmt)

add_library(syfmt format.cpp)

option(BUILD_TESTS "Build all tests" ON)

if(BUILD_TESTS)
  enable_testing()
  add_executable(format_test format_test.cpp)
  target_link_libraries(format_test syfmt)
  add_test(format_test format_test)
endif()
