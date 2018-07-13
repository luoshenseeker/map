cmake_minimum_required(VERSION 3.0.0)
project(WMJTask01Map VERSION 0.1.0)

add_compile_options(
    -Wall
    -std=c++11
)

# 增加 #inlcude 的搜索文件夹范围
include_directories(
    include
)


# 增加可执行文件
add_executable(WMJTask01Map src/main.cpp)
