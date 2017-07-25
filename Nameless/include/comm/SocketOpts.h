//
// Created by CFWLoader on 7/25/17.
//

#ifndef NAMELESS_SOCKETOPTS_H
#define NAMELESS_SOCKETOPTS_H

#include <arpa/inet.h>

namespace nameless::comm::SocketOpts
{
    int createNonblockingOrDie(sa_family_t);

    void closeSocket(int);
}

#endif //NAMELESS_SOCKETOPTS_H
