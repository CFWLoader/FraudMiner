//
// Created by CFWLoader on 7/20/17.
//

#ifndef NAMELESS_SOCKET_H
#define NAMELESS_SOCKET_H

#include <netinet/tcp.h>
#include <arpa/inet.h>

#include <memory>

#include <native/Noncopyable.hpp>

namespace nameless::comm
{
    namespace SocketOpts
    {
        int createNonblockingOrDie(sa_family_t family);

        void closeSocket(int);
    }

    class Socket : nameless::native::Noncopyable
    {
    public:

        explicit Socket(int);

        ~Socket();

        int socketFileDescriptor() const;

        std::shared_ptr<tcp_info> getTcpInfo() const;


    private:

        const int socket_fd__;

    };
}

#endif //NAMELESS_SOCKET_H
