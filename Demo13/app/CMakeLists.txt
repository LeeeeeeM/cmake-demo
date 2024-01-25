# 添加可执行程序的源文件
set(SOURCES main.c)

# 生成可执行程序
add_executable(app ${SOURCES})

# 链接动态库
target_link_libraries(app PRIVATE add)

# 设置可执行程序的输出路径
set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)