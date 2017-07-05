cmake_minimum_required(VERSION 3.7)
project(Nameless)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/NativeFile.h src/native/NativeFile.cpp include/NativeString.h src/native/NativeString.cpp)
add_executable(Nameless ${SOURCE_FILES})