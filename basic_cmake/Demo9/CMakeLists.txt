# cmake的最低版本要求
cmake_minimum_required (VERSION 3.24)

# 项目名称为Project
project (Demo9)

option(MYDEBUG "enable debug compilation" OFF)

# 将生成的可执行文件存放到工程根目录下的bin目录下
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 向当前工程添加存放源文件的子目录
add_subdirectory(src)