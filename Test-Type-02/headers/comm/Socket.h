//
// Created by CFWLoader on 9/13/17.
//

#ifndef TEST_TYPE_02_SOCKET_H
#define TEST_TYPE_02_SOCKET_H

#include <netinet/in.h>

namespace test_type02
{
    namespace comm
    {
        class Socket
        {
        public:

            Socket(uint16_t);

            ~Socket();

            int bind();

            int listen();

            Socket* accept();

            int setNonBlocking();

            int getSocketFileDescriptor() const;

        private:

            Socket();

            int sock_fd_;

            sockaddr_in addr_;

        };
    }
}

#endif //TEST_TYPE_02_SOCKET_H
