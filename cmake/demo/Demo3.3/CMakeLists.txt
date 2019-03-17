cmake_minimum_required(VERSION 2.8) 
# VERSION一定要大写的

project(Demo2)


# 添加源文件
aux_source_directory(. DIR_SRCS)
add_executable(Demo ${DIR_SRCS})


# 添加静态库
add_subdirectory(math)
target_link_libraries(Demo MathFunctions)





