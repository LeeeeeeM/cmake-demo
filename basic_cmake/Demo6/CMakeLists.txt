cmake_minimum_required(VERSION 3.24)

project(Demo6)

set (SRC_LIST ${PROJECT_SOURCE_DIR}/func/func.c)

add_library(func_shared SHARED ${SRC_LIST})

add_library(func_static STATIC ${SRC_LIST})

set_target_properties(func_shared PROPERTIES OUTPUT_NAME "func")
set_target_properties(func_static PROPERTIES OUTPUT_NAME "func")

set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)