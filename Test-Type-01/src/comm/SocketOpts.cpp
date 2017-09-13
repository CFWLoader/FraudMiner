//
// Created by CFWLoader on 7/26/17.
//
#include <unistd.h>
#include <netinet/in.h>

#include <comm/SocketOpts.h>

namespace nameless::comm::SocketOpts
{
    int createNonblockingOrDie(sa_family_t family)
    {
#if VALGRIND
        int sockfd = ::socket(family, SOCK_STREAM, IPPROTO_TCP);
      if (sockfd < 0)
      {
        LOG_SYSFATAL << "sockets::createNonblockingOrDie";
      }

      setNonBlockAndCloseOnExec(sockfd);
#else
        int sockfd = ::socket(family, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
        if (sockfd < 0)
        {
            throw "SocketOpts::createNonblockingOrDie()";
        }
#endif
        return sockfd;
    }

    void closeSocket(int fd__)
    {
        if (::close(fd__) < 0)
        {
            throw "SocketOpts::closeSocket()";
        }
    }
}