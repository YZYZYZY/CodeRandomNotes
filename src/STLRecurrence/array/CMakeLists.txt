# 声明目标为动态库
add_library(array_resr SHARED array.h array.inl)


add_executable(array_test array_test.cpp)

target_link_libraries(array_test array_resr)

# 包含目录
target_include_directories(array_resr PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(array_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# 设置属性确保 CMake 知道链接语言
set_target_properties(array_resr PROPERTIES LINKER_LANGUAGE CXX)