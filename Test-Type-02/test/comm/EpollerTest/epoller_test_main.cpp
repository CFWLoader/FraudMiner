#include <cstring>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>

#include <iostream>

#include <comm/Socket.h>
#include <comm/Epoller.h>



using test_type02::comm::Socket;
using test_type02::comm::Epoller;

using namespace std;

int setNonBlocking(int sock_fd_)
{
    int opts = fcntl(sock_fd_, F_GETFL);

    if(opts < 0)
    {
        throw std::string("FATAL: Socket::setNonBlocking() - fcntl(){F_GETFL}.");
    }

    opts |= O_NONBLOCK;

    int ret_val = fcntl(sock_fd_, F_SETFL, opts);

    if(ret_val < 0)
    {
        throw std::string("FATAL: Socket::setNonBlocking() - fcntl(){F_SETFL}.");
    }

    return ret_val;
}

int test01()
{
    Socket socket(3360);

    socket.setNonBlocking();

    socket.bind();
    socket.listen();

    char send_buf[2048];

    int accepted_count = 0;

    int triggered, handling, handlingFd;

    Epoller epoller(8);

    epoll_event ev;

    char endSig[] = "end\r";

    epoller.registerEpollEvent(socket.getSocketFileDescriptor());

    while (accepted_count > -1)
    {
        triggered = epoller.wait();

        cout << "Handling " << triggered << " events" << endl;

        for (handling = 0; handling < triggered; ++handling)
        {
            if (epoller.getEvents()[handling].data.fd == socket.getSocketFileDescriptor())
            {
                cout << "Registering new client!" << endl;

                handlingFd = socket.accept();

                if (handlingFd < 0)
                {
                    cerr << "Connection failed." << endl;
                } else
                {
                    setNonBlocking(handlingFd);

                    snprintf(send_buf, 2048, "You have successfully connect the host!");

                    send(handlingFd, send_buf, ::strlen(send_buf), 0);

                    ev.data.fd = handlingFd;

                    ev.events = EPOLLIN | EPOLLET;

                    epoller.registerEpollEvent(handlingFd);
                }
            }
            else if(epoller.getEvents()[handling].events & EPOLLIN)
            {
                handlingFd = epoller.getEvents()[handling].data.fd;

                if(handlingFd < 0)
                {
                    cerr << "EPOLLIN happened but failed get the file desciptor." << endl;

                    continue;
                }

                memset(send_buf, 0, 2048);

                char* head = send_buf;

                size_t recvNum = 0;

                int count = 0;

                bool readOk = false;

                while(1)
                {
                    recvNum = recv(handlingFd, head + count, 2048, 0);

                    //BUFFER is empty.
                    if(recvNum < 0 and errno == EAGAIN)
                    {
                        readOk = true;
                    }
                    else if(recvNum < 0)
                    {
                        cerr << "Bad buffering!." << endl;

                        readOk = true;
                    }

                    count += recvNum;

                    if(recvNum == 2048)
                    {
                        continue;
                    }
                    else if (recvNum == 0)              // Receive FIN.
                    {
                        close(handlingFd);

                        epoller.getEvents()[handling].data.fd = -1;

                        break;
                    }
                    else{
                        readOk = true;
                    }

                    if(readOk)
                    {
                        break;
                    }
                }

                printf("Value: %d, rev: %s, len: %u, com: %s, len: %u.\n",
                       send_buf[3], send_buf, strlen(send_buf),
                       endSig, strlen(endSig));

                // receive return as \r.
                if(strcmp(endSig, send_buf) == 0)
                {
                    close(handlingFd);

                    epoller.getEvents()[handling].data.fd = -1;
                }

                send(handlingFd, send_buf, ::strlen(send_buf), 0);
            }
        }
//        int cli_sock = socket.accept();
//
//        if(cli_sock < 0)
//        {
//            break;
//        }
//
//        snprintf(send_buf, 2048, "You have successfully connect the host!");
//
//        send(cli_sock, send_buf, ::strlen(send_buf), 0);
//
//        close(cli_sock);

        ++accepted_count;
    }

    if (accepted_count < 8)
    {
        return -1;
    }

    return 0;
}

int main()
{
    test01();

//    std::cout << "Hello, Socket!" << std::endl;

    return 0;
}