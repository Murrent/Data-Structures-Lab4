cmake_minimum_required(VERSION 3.17)
project(Lab4_Graphs C)

set(CMAKE_C_STANDARD 99)
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(src ${dir}/src)

add_subdirectory(${src}/graph)
add_subdirectory(${src}/list)

add_executable(Lab4_Graphs ${src}/main.c)

target_link_libraries(Lab4_Graphs graph)
target_link_libraries(Lab4_Graphs graph list)