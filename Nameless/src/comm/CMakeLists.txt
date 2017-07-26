set(COMPILE_LIST
        SocketOpts.cpp
        InetAddress.cpp
        Socket.cpp
        )

add_library(nameless_comm SHARED ${COMPILE_LIST})
target_link_libraries(nameless_comm nameless_native)