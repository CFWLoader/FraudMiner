link_directories(${PROJECT_BINARY_DIR}/lib/supports)

set(SOURCE_FILES configuration_loader_test_main.cpp)

add_executable(cl_test ${SOURCE_FILES})

target_link_libraries(cl_test test_type02_supports)