set(SRC_FILES SocketTest.cpp ../SocketOpts/SocketOptsTest.cpp)

link_directories(${PROJECT_BINARY_DIR}/lib/comm)

add_executable(sockettest ${SRC_FILES})

target_link_libraries(sockettest nameless_comm)