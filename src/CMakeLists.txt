cmake_minimum_required(VERSION 3.21)
project(cbfc LANGUAGES C CXX)

file(GLOB_RECURSE sources *.c *.h)

add_executable(${PROJECT_NAME} ${sources})

target_compile_options(${PROJECT_NAME} PUBLIC -Wall)
