cmake_minimum_required(VERSION 3.24)

project(delete)

include_directories(${PROJECT_SOURCE_DIR}/includes)
aux_source_directory(${PROJECT_SOURCE_DIR}/utils UTILS_SRC)
add_library(utils ${UTILS_SRC})


add_executable(main main.c)
target_link_libraries(main utils)