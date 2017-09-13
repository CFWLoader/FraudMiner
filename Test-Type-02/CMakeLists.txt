cmake_minimum_required(VERSION 3.7)
project(Test_Type_02)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/headers)

add_subdirectory(src lib)
add_subdirectory(test)

install(DIRECTORY conf/ DESTINATION ${PROJECT_BINARY_DIR}/conf)

set(SOURCE_FILES main.cpp)
add_executable(Test_Type_02 ${SOURCE_FILES})