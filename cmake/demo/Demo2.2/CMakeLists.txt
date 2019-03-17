cmake_minimum_required(VERSION 2.8) 
# VERSION一定要大写的

project(Demo2)

aux_source_directory(. DIR_SRCS)

add_executable(Demo ${DIR_SRCS})





