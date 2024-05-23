# 声明目标为动态库 为什么我的动态库名字是libarray_resr.dll 不是指定的array_resr.dll？
add_library(array_resr SHARED array.h array.inl)


add_executable(array_test array_test.cpp)

# 指定
target_link_libraries(array_test array_resr)

# 包含目录
target_include_directories(array_resr PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(array_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# 设置属性确保 CMake 知道链接语言
set_target_properties(array_resr PROPERTIES LINKER_LANGUAGE CXX)

#为什么生成的时候会出现bin 和 lib两个文件夹 ，为什么还会生成一个.a的静态库？