# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.5)

# 设置项目名称
project (demo3)

# CMake语法message 使用参考链接: https://www.cnblogs.com/alexYuin/p/8874881.html

## 4.1 环境变量测试
message("--------------------------")
message("4.1 环境变量测试:")

set (TEST_CONFIG_PATH "/usr/local/config")

message(STATUS  "TEST_CONFIG_PATH = ${TEST_CONFIG_PATH}") #测试输出
message("TEST_CONFIG_PATH = ${TEST_CONFIG_PATH}") #测试输出
message(WARNING "TEST_CONFIG_PATH = ${TEST_CONFIG_PATH}")
message("-")

# 4.2 CMake预定义环境变量信息
message("--------------------------")
message("4.2 CMake预定义信息：")
message("PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR}")
message("PROJECT_NAME:${PROJECT_NAME}")
message("CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR:${CMAKE_CURRENT_BINARY_DIR}")
message("CMAKE_CURRENT_LIST_DIR:${CMAKE_CURRENT_LIST_DIR}")

message("-")


# 添加包含头文件路径
include_directories(
     ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 设置生成动态库
add_library(myprint_static STATIC src/print.cpp) # 指定生成静态库
add_library(myprint SHARED src/print.cpp) # 指定生成共享库	

SET_TARGET_PROPERTIES(myprint_static PROPERTIES OUTPUT_NAME "myprint")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #指定可执行文件输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) #指定生成的库的输出目录

message("EXECUTABLE_OUTPUT_PATH:${EXECUTABLE_OUTPUT_PATH}")
message("LIBRARY_OUTPUT_PATH:${LIBRARY_OUTPUT_PATH}")

# 设置链接路径
link_directories(
   	${CMAKE_CURRENT_SOURCE_DIR}/lib #指定库的搜寻路径，相当于gcc -L[lib_path]
)


# 生成ELF可执行文件
add_executable(demo3 src/main.cpp )

# 链接生成的库
 target_link_libraries(demo3 libmyprint.a) 
#target_link_libraries(demo3 libmyprint.so) 