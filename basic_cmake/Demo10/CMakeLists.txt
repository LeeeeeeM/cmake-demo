cmake_minimum_required (VERSION 3.24)

# 项目名称为Project
project (Demo10)

# 将生成的可执行文件存放到工程根目录下的bin目录下
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

option(WWW1 "print one message" OFF)
option(WWW2 "print another message" OFF)

# cmake .. -DTARGET_CPU:STRING=x777
option(TARGET_CPU "cpu type" "MAC")

if (TARGET_CPU) 
    message(${TARGET_CPU})
endif()

if (WWW1)
    add_compile_options(-DWWW1)
endif()

if (WWW2)
    add_compile_options(-DWWW2)
endif()

# 编译源文件main.c，生成可执行文件main
add_executable (main main.c)