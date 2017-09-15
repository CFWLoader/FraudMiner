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

            int bind();

            int listen();

            int accept();

            int setNonBlocking();

            int getSocketFileDescriptor() const;

        private:

            int sock_fd_;

            sockaddr_in host_addr_;

        };
    }
}

#endif //TEST_TYPE_02_SOCKET_H
