cmake_minimum_required(VERSION 3.24)

project(Demo11)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(lib SRC_LIST)

add_executable(app src/main.c ${SRC_LIST})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)