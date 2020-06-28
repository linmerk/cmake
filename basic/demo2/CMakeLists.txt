# 指定CMake最低版本号要求
cmake_minimum_required(VERSION 3.5)

# 设置项目名称
project (demo2)

# 指定包含头文件路径
include_directories(
    include
)

# 添加不同文件夹下面文件
set (SRC
    src/myecho/echo.cpp
    src/myprint/print.cpp
    src/main.cpp
)

# 打印SRC变量值
message(STATUS "SRC: ${SRC}")

# 生成ELF可执行文件
add_executable(demo2 ${SRC})