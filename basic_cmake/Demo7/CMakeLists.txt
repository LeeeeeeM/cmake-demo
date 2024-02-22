cmake_minimum_required (VERSION 3.24)

# 项目名称为Project
project (Demo7)

# 将生成的可执行文件存放到工程根目录下的bin目录下
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 将项目根目录下的/src/main.c文件存到变量SRC_LIST中
set (SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.c)

# 添加指定头文件的搜索路径为项目根目录下的/func/inc目录
include_directories (${PROJECT_SOURCE_DIR}/func/inc)

# 将指定目录下的指定库文件存到变量FUNC_LIB中
find_library(FUNC_LIB func HINTS ${PROJECT_SOURCE_DIR}/lib)

# 编译源文件main.c，生成可执行文件main
add_executable (main ${SRC_LIST})

# 目标文件与库文件进行链接
target_link_libraries (main ${FUNC_LIB})