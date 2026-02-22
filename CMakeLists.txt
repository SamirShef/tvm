cmake_minimum_required(VERSION 3.10)
project(tvm LANGUAGES C)

add_compile_options(-w -g)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})
