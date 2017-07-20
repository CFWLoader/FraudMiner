//
// Created by CFWLoader on 7/20/17.
//
#include <iostream>

#include <comm/Socket.h>

using namespace std;
using namespace nameless::comm;

int constructorTest1()
{
    sockaddr_in addr;

    Socket socket1(SocketOpts::createNonblockingOrDie(addr.sin_family));

    return 0;
}

int main(int argc, char* argv[])
{
    constructorTest1();

    return 0;
}