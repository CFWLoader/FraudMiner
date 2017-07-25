//
// Created by CFWLoader on 7/20/17.
//
#include <string.h>

#include <comm/Socket.h>
#include <comm/SocketOpts.h>

using namespace nameless::comm;

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