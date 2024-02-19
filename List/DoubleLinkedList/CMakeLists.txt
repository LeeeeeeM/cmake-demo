cmake_minimum_required(VERSION 3.24)

project(double_linked_list)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
add_library(src ${SRC})

add_executable(main main.c)
target_link_libraries(main src)