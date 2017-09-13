cmake_minimum_required(VERSION 3.7)
project(Test_Type_02)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/headers)

add_subdirectory(src)
add_subdirectory(test)

set(SOURCE_FILES main.cpp)
add_executable(Test_Type_02 ${SOURCE_FILES})