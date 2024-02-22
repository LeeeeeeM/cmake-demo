cmake_minimum_required(VERSION 3.24)

project(Demo12)

option(LIB "build lib" OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

if (LIB)
aux_source_directory(${PROJECT_SOURCE_DIR}/func SRC_LIST)
add_library(func_shared SHARED ${SRC_LIST})
add_library(func_static STATIC ${SRC_LIST})
set_target_properties(func_shared PROPERTIES OUTPUT_NAME "func")
set_target_properties(func_static PROPERTIES OUTPUT_NAME "func")
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
else()
add_definitions(-DDEBUG)
# 将指定目录下的指定库(func库)文件存到变量FUNC_LIB中
find_library(FUNC_LIB func HINTS ${PROJECT_SOURCE_DIR}/lib)

add_executable(app main.c)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 目标文件与库文件进行链接
target_link_libraries (app ${FUNC_LIB})
endif()



