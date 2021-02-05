cmake_minimum_required(VERSION 3.16.3)
project(cm)

set(CMAKE_CXX_STANDART 11)

add_executable(cm Main.cpp  Matrix.h  Matrix.cpp Vectors.h Vectors.cpp)