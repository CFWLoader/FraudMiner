//
// Created by CFWLoader on 7/26/17.
//
#include <netdb.h>
#include <stddef.h>
#include <cstring>

#include <comm/Endian.hpp>
#include <comm/InetAddress.h>
#include <comm/SocketOpts.h>

// INADDR_ANY use (type)value casting.
#pragma GCC diagnostic ignored "-Wold-style-cast"
static const in_addr_t NAMELESS_COMM_INADDR_ANY = INADDR_ANY;
static const in_addr_t NAMELESS_COMM_INADDR_LOOPBACK = INADDR_LOOPBACK;
#pragma GCC diagnostic error "-Wold-style-cast"

//     /* Structure describing an Internet socket address.  */
//     struct sockaddr_in {
//         sa_family_t    sin_family; /* address family: AF_INET */
//         uint16_t       sin_port;   /* port in network byte order */
//         struct in_addr sin_addr;   /* internet address */
//     };

//     /* Internet address. */
//     typedef uint32_t in_addr_t;
//     struct in_addr {
//         in_addr_t       s_addr;     /* address in network byte order */
//     };

//     struct sockaddr_in6 {
//         sa_family_t     sin6_family;   /* address family: AF_INET6 */
//         uint16_t        sin6_port;     /* port in network byte order */
//         uint32_t        sin6_flowinfo; /* IPv6 flow information */
//         struct in6_addr sin6_addr;     /* IPv6 address */
//         uint32_t        sin6_scope_id; /* IPv6 scope-id */
//     };

using namespace nameless::comm;

static_assert(sizeof(InetAddress) == sizeof(struct sockaddr_in6));
static_assert(offsetof(sockaddr_in, sin_family) == 0);
static_assert(offsetof(sockaddr_in6, sin6_family) == 0);
static_assert(offsetof(sockaddr_in, sin_port) == 2);
static_assert(offsetof(sockaddr_in6, sin6_port) == 2);

#if !(__GNUC_PREREQ (4,6))
#pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif

InetAddress::InetAddress(uint16_t port, bool loopbackOnly, bool ipv6)
{
    static_assert(offsetof(InetAddress, addr6__) == 0);
    static_assert(offsetof(InetAddress, addr__) == 0);

    if(ipv6)
    {
        ::bzero(&addr6__, sizeof(addr6__));

        addr6__.sin6_family = AF_INET6;

        in6_addr ip = loopbackOnly ? in6addr_loopback : in6addr_any;

        addr6__.sin6_addr = ip;

        addr6__.sin6_port = SocketOpts::hostToNetwork16(port);
    }
}