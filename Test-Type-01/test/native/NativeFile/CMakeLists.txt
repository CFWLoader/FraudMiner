#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${INCLUDE_DIR}")
set(SRC_FILES NativeFileTest.cpp)

link_directories(${PROJECT_BINARY_DIR}/lib/native)

add_executable(nativefiletest ${SRC_FILES})

target_link_libraries(nativefiletest nameless_native)