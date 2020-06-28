# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.5)

# 设置项目名称
project (demo3)


message("------------------")
# 添加 option
option (USE_PRINT "use print function!" ON)
if(USE_PRINT)
    add_definitions(-DUSE_PRINT)
    message(STATUS "USE PRINT FUNCTION")
else()
    message(STATUS "DO NOT USE PRINT FUNCTION")
endif(USE_PRINT)

message("------------------")
find_package(Boost REQUIRED)
if(Boost_FOUND)
    message("Boost_VERSION:${Boost_VERSION}")
    message("Boost_INCLUDE_DIRS:${Boost_INCLUDE_DIRS}")
    message("Boost_LIBRARY_DIRS:${Boost_LIBRARY_DIRS}")
else()
    message("could not find Boost")
endif(Boost_FOUND)

message("------------------")
# 包含build.cmake,获取其中设置的变量
include(cmake/build.cmake)

# 添加包含头文件路径
include_directories(
     ${CMAKE_CURRENT_SOURCE_DIR}/include
)

message("------------------")
# 设置生成动态库
add_library(myprint_static STATIC src/print.cpp) # 指定生成静态库
add_library(myprint SHARED src/print.cpp) # 指定生成共享库	

SET_TARGET_PROPERTIES(myprint_static PROPERTIES OUTPUT_NAME "myprint")

message(STATUS "EXECUTABLE_OUTPUT_PATH:${EXECUTABLE_OUTPUT_PATH}")
message(STATUS "LIBRARY_OUTPUT_PATH:${LIBRARY_OUTPUT_PATH}")


# 设置链接路径
link_directories(
    	${CMAKE_CURRENT_SOURCE_DIR}/lib #指定库的搜寻路径，相当于gcc -L[lib_path]
)

# 生成ELF可执行文件
add_executable(demo3 src/main.cpp )

# 链接生成的库
 target_link_libraries(demo3 libmyprint.a) 
#target_link_libraries(demo3 libmyprint.so) 


#############
## Install ##
#############
install(TARGETS demo3 myprint_static myprint
    RUNTIME DESTINATION /usr/local/sbin
    LIBRARY DESTINATION /usr/local/lib
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/print.h
   DESTINATION /usr/local/include
 )

#############
## Uninstall##
#############
set(BINARY_DIRECTOR /usr/local/sbin)
set(LIBRARY_DIRECTOR /usr/local/lib)
set(INCLUDE_DIRECTOR /usr/local/include)

set(CURRENT_BIN demo3)
set(CURRENT_SHARED libmyprint.so)
set(CURRENT_STATIC libmyprint.a)
set(CURRENT_INCLUDE print.h)

add_custom_target(uninstall 
    COMMAND echo "uninstall...." ${BINARY_DIRECTOR}

    COMMAND echo "removing:"${CURRENT_BIN}
    COMMAND cd ${BINARY_DIRECTOR} && rm -rf ${CURRENT_BIN}

    COMMAND echo "removing:"${CURRENT_INCLUDE}
    COMMAND cd ${INCLUDE_DIRECTOR} && rm -rf ${CURRENT_INCLUDE}

    COMMAND echo "removing:"${CURRENT_STATIC}
    COMMAND cd ${LIBRARY_DIRECTOR} && rm -rf ${CURRENT_STATIC}

    COMMAND echo "removing:"${CURRENT_SHARED}
    COMMAND cd ${LIBRARY_DIRECTOR} && rm -rf ${CURRENT_SHARED}
    COMMAND echo "uninstall done !"
)
