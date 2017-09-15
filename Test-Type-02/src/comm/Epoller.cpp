//
// Created by CFWLoader on 9/15/17.
//
#include <sys/epoll.h>

#include <string>

#include <comm/Epoller.h>

using namespace test_type02::comm;


Epoller::Epoller(size_t eventLimits) : events(eventLimits)
{
    epfd_ = epoll_create(eventLimits);

    if(epfd_ < 0)
    {
        throw std::string("Fatal: Epoller::Epoller() - epoll_create().");
    }
}

int Epoller::registerEpollEvent(int sockfd)
{
    epoll_event event;

    event.data.fd = sockfd;

    event.events = EPOLLIN | EPOLLET;

    int rev_val = epoll_ctl(epfd_, EPOLL_CTL_ADD, sockfd, &event);

    if(rev_val < 0)
    {
        throw std::string("Fatal:  Epoller::registerEpollEvent() - epoll_ctl()");
    }

    return rev_val;

}

int Epoller::wait()
{
    int triggered = epoll_wait(epfd_, events.data(), events.size(), -1);
}