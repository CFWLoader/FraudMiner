//
// Created by CFWLoader on 9/13/17.
//
#include <sys/types.h>
#include <sys/socket.h>

#include <cstring>

// Temporarily using syslog.
#include <syslog.h>

#include <comm/Socket.h>


using namespace test_type02::comm;

Socket::Socket(uint16_t host_port) : sock_fd_(::socket(AF_INET, SOCK_STREAM, 0))
{
    ::memset((void*)&host_addr_, 0, sizeof(host_addr_));

    host_addr_.sin_family = AF_INET;

    host_addr_.sin_port = htons(host_port);

    // Accept requests from any addresses.
    host_addr_.sin_addr.s_addr = htonl(INADDR_ANY);

    if(sock_fd_ < 0)
    {
        syslog(LOG_ERR, "%s:%d, Socket::Socket() failed.", __FILE__, __LINE__);
    }

}

int Socket::bind()
{
    int ret_val = ::bind(sock_fd_, (sockaddr*)&host_addr_, sizeof(host_addr_));

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

int Socket::accept()
{
    sockaddr_in cli_addr;

    socklen_t socklen;

    ::memset((void*)&cli_addr, 0, sizeof(cli_addr));

    int cli_sock = ::accept(sock_fd_, (sockaddr*)&cli_addr, &socklen);

    if(cli_sock < 0)
    {
        syslog(LOG_ERR, "%s:%d, Socket::accept() failed.", __FILE__, __LINE__);
    }

    return cli_sock;

}