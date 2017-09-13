link_directories(${PROJECT_BINARY_DIR}/lib/comm)

set(SOURCE_FILES socket_test_main.cpp)

add_executable(socket_test ${SOURCE_FILES})

target_link_libraries(socket_test test_type02_comm)