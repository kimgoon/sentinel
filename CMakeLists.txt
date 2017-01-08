cmake_minimum_required(VERSION 3.4)

project(thunder)

add_definitions(-std=c++14)
add_definitions(-O2)



include_directories("~/sandlab/github/tp/cpp_redis/includes")

include_directories(".")

add_subdirectory(util)
add_subdirectory(net)

add_subdirectory(tests)
