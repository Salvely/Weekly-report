#include <arpa/inet.h>
#include <ifaddrs.h>
#include <iostream>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "client.hh"

Client::Client()
{
	// figure out ip and port number of the server
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = INADDR_ANY;
	memset(addr.sin_zero, 0, sizeof(addr.sin_zero));
}

Client::~Client()
{
	disconnectFromServer();
}

int Client::connectToServer()
{
	// create a socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		std::cerr << "socket creation failed!" << std::endl;
		return -1;
	}
	// connet to the server
	int ret = connect(sock, reinterpret_cast<sockaddr *>(&addr), sizeof(addr));
	if (ret == -1)
	{
		std::cerr << "connection failed!" << std::endl;
		return -1;
	}
	return 0;
}

void Client::chat()
{
	while (1)
	{
		int n = 0;
		std::cout << "Client: ";
		bzero(send_buf, 1024);
		while ((send_buf[n++] = getchar()) != '\n')
			;
		// send message to the server
		int wcount = write(sock, send_buf, 1024);

		char recv_buf[1024];
		// receive message from the server
		int rcount = read(sock, recv_buf, 1024);
		fprintf(stdout, "Server said: %s", recv_buf);
	}
}

void Client::disconnectFromServer()
{
	close(sock);
}

int main(void)
{
	Client c;
	c.connectToServer();
	c.chat();
	c.disconnectFromServer();
}