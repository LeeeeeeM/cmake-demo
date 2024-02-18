cmake_minimum_required(VERSION 3.24)

project(insert)

include_directories(${PROJECT_SOURCE_DIR}/includes)

aux_source_directory(${PROJECT_SOURCE_DIR}/utils UTILS_SRC)
add_library(utils ${UTILS_SRC})


add_executable(last last.c)
add_executable(head head.c)

target_link_libraries(last utils)
target_link_libraries(head utils)