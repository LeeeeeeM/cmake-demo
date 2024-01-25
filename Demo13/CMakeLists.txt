cmake_minimum_required(VERSION 3.24)
project(project)

# 设置 C 编译器
set(CMAKE_C_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/includes)

# 添加子目录
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(main)

# add_dependencies(app src)