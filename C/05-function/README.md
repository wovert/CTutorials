cmake_minimum_required(VERSION 3.24)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
#project(05_function C)
project(${ProjectId} C)

set(CMAKE_C_STANDARD 11)

include_directories("include")

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach(file ${files})
get_filename_component(name ${file} NAME)
add_executable(${name} ${file} src/main.c)
target_compile_definitions(${name} PUBLIC DEBUG)
endforeach()