//
// Created by CFWLoader on 9/13/17.
//
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstring>
#include <string>
//#include <iostream>

// Temporarily using syslog.
#include <syslog.h>

#include <comm/Socket.h>


using namespace test_type02::comm;

Socket::Socket()
{}

Socket::Socket(uint16_t host_port) : sock_fd_(::socket(AF_INET, SOCK_STREAM, 0))
{
    ::memset((void*)&addr_, 0, sizeof(addr_));

    addr_.sin_family = AF_INET;

    addr_.sin_port = htons(host_port);

    // Accept requests from any addresses.
    addr_.sin_addr.s_addr = htonl(INADDR_ANY);

    if(sock_fd_ < 0)
    {
        syslog(LOG_ERR, "%s:%d, Socket::Socket() failed.", __FILE__, __LINE__);
    }

}

Socket::~Socket()
{
//    std::cout << "A socket is being closed." << std::endl;

    if(sock_fd_ == -1)
    {
        return;
    }

    ::close(sock_fd_);

    sock_fd_ = -1;
}

int Socket::bind()
{
    int ret_val = ::bind(sock_fd_, (sockaddr*)&addr_, sizeof(addr_));

    if(ret_val < 0)
    {
        syslog(LOG_ERR, "%s:%d, Socket::bind() failed.", __FILE__, __LINE__);
    }

    return ret_val;
}

int Socket::listen()
{
    int ret_val = ::listen(sock_fd_, 32);

    if(ret_val < 0)
    {
        syslog(LOG_ERR, "%s:%d, Socket::listen() failed.", __FILE__, __LINE__);
    }

    return ret_val;
}

Socket* Socket::accept()
{
    // sockaddr_in cli_addr;

    Socket* cli_sock = new Socket();

    socklen_t socklen;

    ::memset((void*)&(cli_sock->addr_), 0, sizeof(cli_sock->addr_));

    cli_sock->sock_fd_ = ::accept(sock_fd_, (sockaddr*)&(cli_sock->addr_), &socklen);

    if(cli_sock->sock_fd_ < 0)
    {
        syslog(LOG_ERR, "%s:%d, Socket::accept() failed.", __FILE__, __LINE__);
    }

    return cli_sock;

}

int Socket::setNonBlocking()
{
    int opts = fcntl(sock_fd_, F_GETFL);

    if(opts < 0)
    {
        throw std::string("FATAL: Socket::setNonBlocking() - fcntl(){F_GETFL}.");
    }

    opts |= O_NONBLOCK;

    int ret_val = fcntl(sock_fd_, F_SETFL, opts);

    if(ret_val < 0)
    {
        throw std::string("FATAL: Socket::setNonBlocking() - fcntl(){F_SETFL}.");
    }

    return ret_val;
}

int Socket::getSocketFileDescriptor() const
{
    return sock_fd_;
}