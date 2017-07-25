//
// Created by CFWLoader on 7/25/17.
//
#include <unistd.h>

#include <comm/SocketOpts.h>
// #include <sys/socket.h>
// #include <sys/types.h>

using namespace nameless::comm::SocketOpts;

int createNonblockingOrDie(sa_family_t family)
{
#if VALGRIND

    int sockfd = ::socket(family, SOCK_STREAM, IPPROTO_TCP);

        if(sockfd < 0)
        {
            throw "SocketOpts::createNonblockingOrDie";
        }

        setNonBlockAndCloseOnExec(sockfd);

#else

    int sockfd = ::socket(family, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);

    if (sockfd < 0)
    {
        throw "SocketOpts::createNonblockingOrDie";
    }

#endif
}

void closeSocket(int sockfd)
{
    if(::close(sockfd))
    {
        throw "SocketOpts::close()";
    }
}