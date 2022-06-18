cmake_minimum_required(VERSION 3.20)

Project(CoreGraphics)

file(GLOB_RECURSE CORE_SOURCE src/*.hpp src/*cpp)

add_library(${PROJECT_NAME} ${CORE_SOURCE})