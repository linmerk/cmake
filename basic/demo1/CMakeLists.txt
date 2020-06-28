# 指定CMake最低版本号要求
cmake_minimum_required(VERSION 3.5)

# 指定项目名称
project (demo1)

# 指定包含头文件路径
include_directories(
    include
)

# 将当前CMakeLists.txt所在目录下src文件夹里面所有文件(main.cpp, myprint.cpp),添加到变量SRC
aux_source_directory(./src SRC)

# 打印SRC变量值
message(STATUS "SRC: ${SRC}")

# 指定生成可执行文件
add_executable(demo1 ${SRC})