cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME CadLib)

add_library(${PROJECT_NAME} SHARED Curves.h Curves.cpp)