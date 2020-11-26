cmake_minimum_required(VERSION 3.16)
project(ED2020_SVMK)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(ED2020_SVMK main.cpp)

add_executable(ED2020_SVMK ${ED2020_SVMK})