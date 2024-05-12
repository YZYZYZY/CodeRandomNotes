cmake_minimum_required(VERSION 3.29.0)
project(STLandAlogrithm
    VERSION 0.0.1
    DESCRIPTION "reproduce STL containers and learn correspinding algorithms"
    HOMEPAGE_URL "https://github.com/YZYZYZY/cmake_planning_test"
    LANGUAGES CXX
)
#设置C++标准
set(CMAKE_CXX_STANDARD 17)

#设置变量 只需要设置可执行文件的输出路径 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#添加子目录 
add_subdirectory(src) 
