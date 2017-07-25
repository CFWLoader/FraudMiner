//
// Created by CFWLoader on 7/20/17.
//
#include <string.h>
#include <netinet/in.h>

#include <comm/Socket.h>
#include <unistd.h>

using namespace nameless::comm;

int SocketOpts::createNonblockingOrDie(sa_family_t family)
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

void SocketOpts::closeSocket(int fd__)
{
    if(::close(fd__) < 0)
    {
        throw "SocketOpts::closeSocket()";
    }
}

Socket::Socket(int sockfd) : socket_fd__(sockfd)
{}

Socket::~Socket()
{
    SocketOpts::closeSocket(socket_fd__);
}

int Socket::socketFileDescriptor() const
{
    return socket_fd__;
}

std::shared_ptr<tcp_info> Socket::getTcpInfo() const
{
    tcp_info* info = new tcp_info;

    socklen_t len = sizeof(*info);

    bzero(info, len);

    if(::getsockopt(socket_fd__, SOL_TCP, TCP_INFO, info, &len) != 0)
    {
        throw "nameless::comm::Socket::getTcpInfo()";
    }

    return std::shared_ptr<tcp_info>(info);
}