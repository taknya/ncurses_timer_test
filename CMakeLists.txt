cmake_minimum_required(VERSION 3.24)
project(timer_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(timer_test main.cpp)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(timer_test ${CURSES_LIBRARIES})