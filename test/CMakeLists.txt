cmake_minimum_required(VERSION 3.10)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/googletest/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/googletest/
)

add_executable(format_test format_test.cpp googletest/src/gtest_main.cc googletest/src/gtest-all.cc)
target_link_directories(format_test PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(format_test syfmt)
add_test(format_test format_test)
