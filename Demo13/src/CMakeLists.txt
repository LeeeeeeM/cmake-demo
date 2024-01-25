# 添加动态链接库的源文件
set(SOURCES add.c)
# 生成动态链接库
add_library(add SHARED ${SOURCES})

# 指定动态链接库的输出名称和版本信息
set_target_properties(add PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
    OUTPUT_NAME add
    MACOSX_RPATH ON
)