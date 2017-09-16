from socket import *

MAX_BUF_SIZE = 2048

class TcpClient:

    def __init__(self, host, port):

        self.host_addr = (host, port)

        self.client = socket(AF_INET, SOCK_STREAM)

        self.client.connect(self.host_addr)

    def loop(self, message, limit):

        for idx in range(0, limit):

            self.client.send(message.encode('utf-8'))

            ret_data = self.client.recv(MAX_BUF_SIZE)

            if not ret_data:

                raise Exception("Host failed returning.")

                break

    def close(self):

        self.client.close()

if __name__ == '__main__':

    cli = TcpClient('127.0.0.1', 3360)

    cli.loop('Hello!', 16)

    cli.close()
