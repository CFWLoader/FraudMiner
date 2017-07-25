//
// Created by CFWLoader on 7/20/17.
//
#include <iostream>

#include <comm/Socket.h>

using namespace std;
using namespace nameless::comm;
//using namespace nameless::comm::SocketOpts;

int constructorTest1()
{
    sockaddr_in addr;

    Socket socket1(SocketOpts::createNonblockingOrDie(addr.sin_family));

    return 0;
}

//int getTcpInfoTest()
//{
//    sockaddr_in addr;
//
//    Socket socket1(SocketOpts::createNonblockingOrDie(addr.sin_family));
//
//    shared_ptr<tcp_info> tcpInfo = socket1.getTcpInfo();
//
//    cout << tcpInfo->tcpi_ato << endl;
//
//    return 0;
//}

int main(int argc, char* argv[])
{
     constructorTest1();

//    getTcpInfoTest();

    return 0;
}