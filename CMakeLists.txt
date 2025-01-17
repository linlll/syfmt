cmake_minimum_required(VERSION 3.10)

project(syfmt)

set(CMAKE_CXX_STANDARD 17)

set(SYFMT_VERSION_MAJOR 0)
set(SYFMT_VERSION_MINOR 0)
set(SYFMT_VERSION_PATCH 0)
set(SYFMT_VERSION ${SYFMT_VERSION_MAJOR}.${SYFMT_VERSION_MINOR}.${SYFMT_VERSION_PATCH})

option(SYFMT_BUILD_TESTS "Build all tests" ON)
option(SYFMT_BUILD_SHARED "Build shared library" ON)
option(SYFMT_BUILD_PIC "Build position independent code (-fPIC)" ON)

if(SYFMT_BUILD_PIC)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

include_directories(include)

file(GLOB ALL_SRCS src/*.cpp)
file(GLOB ALL_INLINE_HEADER include/*-inl.h)
file(GLOB ALL_HEADER include/*.h)
list(REMOVE_ITEM ALL_HEADER ${ALL_INLINE_HEADER})

if(SYFMT_BUILD_SHARED)
  message(STATUS "build shared library")
  add_library(syfmt SHARED ${ALL_SRCS} ${ALL_HEADER})
else()
message(STATUS "build static library")
  add_library(syfmt STATIC ${ALL_SRCS} ${ALL_HEADER})
endif()

set_target_properties(syfmt PROPERTIES VERSION ${SYFMT_VERSION} SOVERSION
        ${SYFMT_VERSION_MAJOR}.${SYFMT_VERSION_MINOR})
set_target_properties(syfmt PROPERTIES DEBUG_POSTFIX d)

add_library(syfmt::syfmt ALIAS syfmt)

if(SYFMT_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test/)

  if(WIN32)
    # In windows system, the system variable *Path* need to be set, then the executable program can
    # find the dynamic library. Or, we just copy the dynamic library to the path of the executable
    # program simply.
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
      set(LIB_NAME "libsyfmtd.dll")
    else()
      set(LIB_NAME "libsyfmt.dll")
    endif()
    add_custom_target(COPY_TARGET ALL)
    add_custom_command(TARGET COPY_TARGET POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${LIB_NAME} ${CMAKE_BINARY_DIR}/test/)
    # COPY_TARGET is an empty target used to fill the TARGET option in *add_custom_command*, with
    # the ultimate goal of only copying dynamic library files. So, syfmt need to be compiled 
    # before COPY_TARGET.
    add_dependencies(COPY_TARGET syfmt)
  endif()
endif()
