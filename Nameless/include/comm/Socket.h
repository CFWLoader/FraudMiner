//
// Created by CFWLoader on 7/20/17.
//

#ifndef NAMELESS_SOCKET_H
#define NAMELESS_SOCKET_H

#include <netinet/tcp.h>

#include <memory>

#include <native/ClassAttributes.hpp>
#include <comm/InetAddress.h>

namespace nameless::comm
{
    class Socket : nameless::native::ClassAttributes::Noncopyable
    {
    public:

        explicit Socket(int);

        ~Socket();

        int socketFileDescriptor() const;

        std::shared_ptr<tcp_info> getTcpInfo() const;

        std::shared_ptr<std::string> getTcpInfoString() const;

        bool bindAddress(const InetAddress& localAddr);


    private:

        const int socket_fd__;

    };
}

#endif //NAMELESS_SOCKET_H
