#include <arpa/inet.h>
#include <ifaddrs.h>
#include <iostream>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "server.hh"
#include <sys/wait.h>

Server::Server()
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

	// initialize the cond variable
	pthread_cond_init(&cond, NULL);
	// initialize the mutex
	pthread_mutex_init(&mutex, NULL);
}
Server::~Server()
{
	disconnect();
	// destroy the cond variable
	pthread_cond_destroy(&cond);
	// destroy the mutex variable
	pthread_mutex_destroy(&mutex);
}

int Server::acceptConnection()
{
	while (1)
	{
		// 5) accept() a client connection
		int len = sizeof(addr);
		int conn = accept(sock, reinterpret_cast<struct sockaddr *>(&addr),
						  reinterpret_cast<socklen_t *>(&len));
		conn_queue.push(conn);
		pthread_cond_signal(&cond);
		if (conn == -1)
		{
			std::cerr << "Port accept failed!" << std::endl;
			return -1;
		}
	}
}

void Server::chat()
{
	while (1)
	{
		pthread_cond_wait(&cond, &mutex);
		pthread_mutex_lock(&mutex);
		int conn = conn_queue.back();
		conn_queue.pop();
		// 6) .read() and write() to that connection
		// receive message from the server
		int rcount = read(conn, recv_buf, 1024);
		fprintf(stdout, "Client said: %s", recv_buf);

		bzero(recv_buf, 1024);
		int n = 0;
		std::cout << "Server said: ";
		while ((recv_buf[n++] = getchar()) != '\n')
			;
		// send message to the server
		int wcount = write(conn, recv_buf, 1024);
		pthread_mutex_unlock(&mutex);
	}
}

void Server::disconnect()
{
	// 7) close() the client socket
	close(sock);
}

int main(void)
{
	Server s;
	pid_t child1 = fork();
	if (child1 == 0)
	{
		s.acceptConnection();
	}
	pid_t child2 = fork();
	if (child2 == 0)
	{
		s.chat();
	}
	wait(NULL);
	wait(NULL);
	s.disconnect();
}