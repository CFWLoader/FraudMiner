cmake_minimum_required(VERSION 3.7)
project(Nameless)

set(CMAKE_CXX_STANDARD 11)

#set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${INCLUDE_DIR}")

# message(${INCLUDE_DIR})

add_subdirectory(src lib)
add_subdirectory(test bin)

#set(SOURCE_FILES main.cpp)
#add_executable(Nameless ${SOURCE_FILES})