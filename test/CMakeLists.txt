cmake_minimum_required(VERSION 3.10)

find_package(Threads REQUIRED)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/googletest/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/googletest/
)

add_executable(format_test format_test.cpp googletest/src/gtest_main.cc googletest/src/gtest-all.cc)
target_link_libraries(format_test PRIVATE syfmt Threads::Threads)
add_test(format_test format_test)
