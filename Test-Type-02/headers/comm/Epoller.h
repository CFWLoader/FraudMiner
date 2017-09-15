//
// Created by CFWLoader on 9/15/17.
//

#ifndef TEST_TYPE_02_EPOLLER_H
#define TEST_TYPE_02_EPOLLER_H

#include <vector>

#include <cstddef>

namespace test_type02
{
    namespace comm
    {
        class Epoller
        {
        public:

            Epoller(size_t = 64);

            int registerEpollEvent(int sockfd);

            int wait();

            std::vector<epoll_event>& getEvents();

        private:

//            size_t eventsLimit_;

            int epfd_;

            std::vector<epoll_event> events;

        };
    }
}

#endif //TEST_TYPE_02_EPOLLER_H
