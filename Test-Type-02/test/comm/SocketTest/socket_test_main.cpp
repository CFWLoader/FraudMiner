#include <cstring>
#include <unistd.h>

#include <iostream>

#include <comm/Socket.h>


using test_type02::comm::Socket;

int test01()
{
    Socket socket(3360);

    socket.bind();
    socket.listen();

    char send_buf[2048];

    int accepted_count = 0;

    while(accepted_count < 8)
    {
        int cli_sock = socket.accept();

        if(cli_sock < 0)
        {
            break;
        }

        snprintf(send_buf, 2048, "You have successfully connect the host!");

        send(cli_sock, send_buf, ::strlen(send_buf), 0);

        close(cli_sock);

        ++accepted_count;
    }

    if(accepted_count < 8)
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