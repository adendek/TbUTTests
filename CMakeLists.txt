cmake_minimum_required(VERSION 3.2)
add_definitions(-std=c++11)
project(TbUTTests)

enable_testing()

add_subdirectory(test)
add_subdirectory(src)

