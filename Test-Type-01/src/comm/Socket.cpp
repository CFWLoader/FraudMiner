//
// Created by CFWLoader on 7/20/17.
//
#include <cstring>

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

std::shared_ptr<std::string> Socket::getTcpInfoString() const
{
    std::shared_ptr<tcp_info> info = this->getTcpInfo();

    char buf[1024];

    snprintf(buf, 1024, "unrecoverd=%u "
            "rto=%u ato=%u snd_mss=%u rcv_mss=%u "
            "lost=%u retrans=%u rtt=%u trrvar=%u "
            "sshthresh=%u cwnd=%u total_retrans=%u",
             info->tcpi_retransmits,  // Number of unrecovered [RTO] timeouts
             info->tcpi_rto,          // Retransmit timeout in usec
             info->tcpi_ato,          // Predicted tick of soft clock in usec
             info->tcpi_snd_mss,
             info->tcpi_rcv_mss,
             info->tcpi_lost,         // Lost packets
             info->tcpi_retrans,      // Retransmitted packets out
             info->tcpi_rtt,          // Smoothed round trip time in usec
             info->tcpi_rttvar,       // Medium deviation
             info->tcpi_snd_ssthresh,
             info->tcpi_snd_cwnd,
             info->tcpi_total_retrans  // Total retransmits for entire connection
    );

    return std::shared_ptr<std::string>(new std::string(buf));
}

bool Socket::bindAddress(const InetAddress& localAddr)
{
    return true;
}