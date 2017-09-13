set(SRC_FILES NamelessGraphTest.cpp)

link_directories(${PROJECT_BINARY_DIR}/lib/native)

add_executable(namelessgraphtest ${SRC_FILES})

target_link_libraries(namelessgraphtest nameless_native)