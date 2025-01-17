cmake_minimum_required(VERSION 3.10)

project(syfmt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

option(SYFMT_BUILD_TESTS "Build all tests" ON)
option(SYFMT_BUILD_SHARED "Build shared library" ON)

include_directories(include)

file(GLOB ALL_SRCS src/*.cpp)
file(GLOB ALL_HEADER include/*.h)

if(SYFMT_BUILD_SHARED)
  message(STATUS "build shared library")
  add_library(syfmt SHARED ${ALL_SRCS} ${ALL_HEADER})
else()
  add_library(syfmt STATIC ${ALL_SRCS} ${ALL_HEADER})
endif()

if(SYFMT_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test/)
endif()
