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

add_library(
    MAP_TEST_LIB
    src/test_lib/map_test.cpp
)


# 增加可执行文件
add_executable(WMJTask01Map src/main.cpp)

target_link_libraries(
    WMJTask01Map
    MAP_TEST_LIB
)