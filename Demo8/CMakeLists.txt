# cmake的最低版本要求
cmake_minimum_required (VERSION 3.24)

# 项目名称为Project
project (Demo8)

# 将生成的可执行文件存放到工程根目录下的bin目录下
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加C++ 11标准支持，并让编译器对代码提出尽可能多的警告
# add_compile_options(-std=c++11 -Wall)
add_compile_options(-std=c11 -Wall -g)

# 编译源文件main.c，生成可执行文件main
add_executable (main main.c)