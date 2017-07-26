//
// Created by CFWLoader on 7/26/17.
//

#ifndef NAMELESS_SOCKETOPTS_H_H
#define NAMELESS_SOCKETOPTS_H_H

namespace nameless::comm::SocketOpts
{
    int createNonblockingOrDie(sa_family_t family);

    void closeSocket(int);
}

#endif //NAMELESS_SOCKETOPTS_H_H
