#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <sys/wait.h>
/**
 * input command into the shell
 * the shell will fork a child and execute the command
 */
int main(void)
{
	std::string s;
	std::getline(std::cin, s);
	std::vector<std::string> lst;
	boost::algorithm::split(lst, s, boost::algorithm::is_any_of("|"), boost::algorithm::token_compress_on);

	for (auto &item : lst)
	{
		boost::algorithm::trim(item);
		std::cout << item << std::endl;
	}

	int fds[2];
	int ret = pipe(fds);
	if (ret == -1)
	{
		std::cerr << "Pipe creation failed!" << std::endl;
		exit(EXIT_SUCCESS);
	}

	// (STDIN -> execvp -> STDOUT -> (pipe) -> STDIN -> execvp -> (STDOUT) -> pipe) -> STDIN -> execvp -> STDOUT)
	pid_t child = fork();
	if (child == 0)
	{
		// parse filename and args
		std::string command1 = lst[0];

		std::vector<std::string> args;
		boost::algorithm::split(args, command1, boost::is_any_of(" "), boost::token_compress_on);
		int argc = args.size();

		const char *filename = args[0].c_str();
		char **argv = new char *[argc + 1];
		for (int i = 0; i < argc; i++)
		{
			std::string args_str = args[i];
			argv[i] = new char[10];
			strcpy(argv[i], args_str.c_str());
		}
		argv[argc] = nullptr;

		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);

		// STDIN -> execvp -> STDOUT -> pipe
		execvp(filename, argv);
	}
	else
	{
		wait(NULL);
		// parse filename and args
		std::string command2 = lst[1];

		std::vector<std::string> args;
		boost::algorithm::split(args, command2, boost::is_any_of(" "), boost::token_compress_on);
		int argc = args.size();

		const char *filename = args[0].c_str();
		char **argv = new char *[argc + 1];
		for (int i = 0; i < argc; i++)
		{
			std::string args_str = args[i];
			argv[i] = new char[10];
			strcpy(argv[i], args_str.c_str());
		}
		argv[argc] = nullptr;

		close(fds[1]);
		dup2(fds[0], 0);
		close(fds[0]);

		// pipe -> STDIN -> execvp -> STDOUT
		execvp(filename, argv);
	}

	exit(EXIT_SUCCESS);
}