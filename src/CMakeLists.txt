cmake_minimum_required(VERSION 3.20)
project(MyDDL_SETR)

#  Set C standard
set(CMAKE_C_STANDARD 99)

#  Include module directory
include_directories(${CMAKE_SOURCE_DIR}/src/module)

#  Add library for MyDLL
add_library(MyDLL module/MyDLL.c)

#  Main executable
add_executable(main main.c)
target_link_libraries(main MyDLL)

#  Test executable
add_executable(tests tests.c)
target_link_libraries(tests MyDLL)
