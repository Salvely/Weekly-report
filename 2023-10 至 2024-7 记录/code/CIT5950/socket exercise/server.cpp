#include <arpa/inet.h>
#include <ifaddrs.h>
#include <iostream>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(void)
{
	// 1) Figure out the IP address and port on which to listen
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = INADDR_ANY;
	memset(addr.sin_zero, 0, sizeof(addr.sin_zero));
	// 2) Create a socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		std::cerr << "socket creation failed!" << std::endl;
		exit(EXIT_FAILURE);
	}
	// 3) bind() the socket to the address(es) and port
	int ret =
		bind(sock, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr));
	if (ret == -1)
	{
		std::cerr << "Addr bind failed!" << std::endl;
		exit(EXIT_FAILURE);
	}
	// 4) Tell the socket to listen() for incoming clients
	ret = listen(sock, 100);
	if (ret == -1)
	{
		std::cerr << "Port listen failed!" << std::endl;
		exit(EXIT_FAILURE);
	}
	// 5) accept() a client connection
	int len = sizeof(addr);
	int conn = accept(sock, reinterpret_cast<struct sockaddr *>(&addr),
					  reinterpret_cast<socklen_t *>(&len));
	if (ret == -1)
	{
		std::cerr << "Port accept failed!" << std::endl;
		exit(EXIT_FAILURE);
	}

	char recv_buf[100];
	char write_buf[100];
	while (1)
	{
		// 6) .read() and write() to that connection
		// receive message from the server
		int rcount = read(conn, recv_buf, 100);
		fprintf(stdout, "Client said: %s", recv_buf);

		bzero(write_buf, 100);
		int n = 0;
		std::cout << "Server said: ";
		while ((write_buf[n++] = getchar()) != '\n')
			;
		// send message to the server
		int wcount = write(conn, write_buf, 100);
	}

	// 7) close() the client socket
	close(sock);
	return EXIT_SUCCESS;
}