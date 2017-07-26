//
// Created by CFWLoader on 7/26/17.
//

#ifndef NAMELESS_INETADDRESS_H
#define NAMELESS_INETADDRESS_H

#include <netinet/in.h>

#include <string>

#include <native/ClassAttributes.hpp>


namespace nameless::comm
{
    namespace SocketOpts
    {
        const sockaddr* sockaddr_cast(const sockaddr_in6*);
    }

    class InetAddress : public nameless::native::ClassAttributes::Copyable
    {
    public:

        explicit InetAddress(uint16_t = 0, bool = false, bool = false);

        InetAddress(std::string, uint16_t, bool = false);

        explicit InetAddress(const sockaddr_in&);

        explicit InetAddress(const sockaddr_in6&);

        sa_family_t family() const;

        std::string toIp() const;

        std::string toIpPort() const;

        uint16_t toPort() const;

        const sockaddr* getSockAddr() const;

        void setSockAddrInet6(const sockaddr_in6&);

        uint32_t ipNetEndian() const;

        uint16_t portNetEndian() const;

        static bool resolve(std::string, InetAddress*);

    private:

        union
        {
            sockaddr_in addr__;

            sockaddr_in6 addr6__;
        };
    };
}

#endif //NAMELESS_INETADDRESS_H
