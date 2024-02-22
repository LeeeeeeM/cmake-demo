cmake_minimum_required(VERSION 3.24)

project(Demo4)

include_directories(func1 func2)

aux_source_directory(func1 SRC_LIST1)
aux_source_directory(func2 SRC_LIST2)

add_executable(main  main.c ${SRC_LIST1} ${SRC_LIST2})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)