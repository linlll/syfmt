cmake_minimum_required(VERSION 3.10)

project(syfmt)

option(SYFMT_BUILD_TESTS "Build all tests" ON)
option(SYFMT_BUILD_SHARED "Build shared library" ON)

include_directories(include)

file(GLOB ALL_SRCS src/*.cpp)

if(SYFMT_BUILD_SHARED)
  message(STATUS "build shared library")
  add_library(syfmt SHARED ${ALL_SRCS})
else()
  add_library(syfmt STATIC ${ALL_SRCS})
endif()

if(SYFMT_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test/)
endif()
