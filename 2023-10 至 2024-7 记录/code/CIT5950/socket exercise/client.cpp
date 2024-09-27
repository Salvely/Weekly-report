#include <arpa/inet.h>
#include <ifaddrs.h>
#include <iostream>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	// figure out ip and port number of the server
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = INADDR_ANY;
	memset(addr.sin_zero, 0, sizeof(addr.sin_zero));

	// create a socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		std::cerr << "socket creation failed!" << std::endl;
		exit(EXIT_FAILURE);
	}
	// connet to the server
	int ret = connect(sock, reinterpret_cast<sockaddr *>(&addr), sizeof(addr));
	if (ret == -1)
	{
		std::cerr << "connection failed!" << std::endl;
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		char write_buf[100];
		int n = 0;
		std::cout << "Client: ";
		bzero(write_buf, 100);
		while ((write_buf[n++] = getchar()) != '\n')
			;
		// send message to the server
		int wcount = write(sock, write_buf, 100);

		char recv_buf[100];
		// receive message from the server
		int rcount = read(sock, recv_buf, 100);
		fprintf(stdout, "Server said: %s", recv_buf);
	}

	// close the socket
	close(sock);
}