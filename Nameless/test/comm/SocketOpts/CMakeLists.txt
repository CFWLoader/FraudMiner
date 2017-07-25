set(SRC_FILES SocketOptsTest.cpp)

link_directories(${PROJECT_BINARY_DIR}/lib/comm)

add_executable(socketoptstest ${SRC_FILES})

target_link_libraries(socketoptstest nameless_comm)