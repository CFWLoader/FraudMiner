//
// Created by CFWLoader on 7/20/17.
//
#include <netinet/in.h>

#include <iostream>

#include <comm/SocketOpts.h>
#include <comm/Socket.h>


using namespace std;
using namespace nameless::comm;
//using namespace nameless::comm::SocketOpts;

int testConstructor1()
{
    sockaddr_in addr;

    Socket socket1(createNonblockingOrDie(addr.sin_family));

    return 0;
}

int testGetTcpInfo1()
{
    sockaddr_in addr;

    Socket socket1(createNonblockingOrDie(addr.sin_family));

    shared_ptr<tcp_info> tcpInfo = socket1.getTcpInfo();

    cout << tcpInfo->tcpi_ato << endl;

    return 0;
}

int main(int argc, char* argv[])
{
    testGetTcpInfo1();

    return 0;
}