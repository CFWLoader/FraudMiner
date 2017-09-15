link_directories(${PROJECT_BINARY_DIR}/lib/comm)

set(SOURCE_FILES epoller_test_main.cpp)

add_executable(epoller_test ${SOURCE_FILES})

target_link_libraries(epoller_test test_type02_comm)