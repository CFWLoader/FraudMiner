#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${INCLUDE_DIR}")
set(SRC_FILES GraphLoaderTest.cpp)

link_directories(${PROJECT_BINARY_DIR}/lib/native)

add_executable(graphloadertest ${SRC_FILES})

target_link_libraries(graphloadertest nameless)