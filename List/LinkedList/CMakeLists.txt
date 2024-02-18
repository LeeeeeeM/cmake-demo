cmake_minimum_required(VERSION 3.24)

project(delete)

include_directories(${PROJECT_SOURCE_DIR}/includes)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
add_library(utils ${SRC})


add_executable(main main.c)
add_executable(main1 main1.c)
target_link_libraries(main1 utils)
target_link_libraries(main utils)