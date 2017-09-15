set(COMPILE_LIST
        Socket.cpp
        Epoller.cpp
        )

add_library(test_type02_comm SHARED ${COMPILE_LIST})