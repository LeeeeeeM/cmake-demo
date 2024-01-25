cmake_minimum_required(VERSION 3.24)

project(Demo3)

set(SRC_LIST ./main.c ./func.c)

add_executable(main ${SRC_LIST})