/*
 * Copyright ©2023 Travis McGaha.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Pennsylvania
 * CIT 5950 for use solely during Spring Semester 2023 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

#include <unistd.h>    // for fork()
#include <sys/types.h> // for pid_t
#include <sys/wait.h>  // for wait(), waitpid(), etc.

#include <cstdlib> // for exit(), EXIT_SUCCESS, and EXIT_FAILURE
#include <iostream>
#include <vector>
#include <string.h>
#include <boost/algorithm/string.hpp>

using namespace std;

#define BUF_SIZ 1000

int main()
{
    string s;
    cout << "$ ";
    while (getline(std::cin, s))
    {
        if (s == "exit")
        {
            return EXIT_SUCCESS;
        }

        int fd[2];
        int in_fd = 0; // input fd

        // split the command into multiple parts
        vector<string> tokens;
        boost::algorithm::split(tokens, s, boost::is_any_of("|"), boost::token_compress_on);

        int count = 1;
        int command_num = tokens.size();

        for (auto &command : tokens)
        {
            // initialize a pipe
            if (pipe(fd) == -1)
            {
                perror("pipe creation failed!");
                return EXIT_FAILURE;
            }

            // prepare to run the current command

            // get the current command
            boost::algorithm::trim(command);
            // split the command into an array of args
            vector<string> args;
            boost::algorithm::split(args, command, boost::is_any_of(" "), boost::token_compress_on);
            int argc = args.size();
            if (argc < 1)
            {
                cerr << "We need a command!" << endl;
                return EXIT_FAILURE;
            }

            // run the current command
            pid_t child = fork();
            if (child == 0)
            {
                // setup the file name and input arguments
                const char *filename = args[0].c_str();
                char **argv = new char *[argc + 1];
                for (int i = 0; i < argc; i++)
                {
                    string args_str = args[i];
                    argv[i] = new char[10];
                    strcpy(argv[i], args_str.c_str());
                }
                argv[argc] = nullptr;

                if (in_fd != 0)
                {
                    // write the pipe value into stdin
                    dup2(in_fd, STDIN_FILENO);
                    close(in_fd);
                }

                if (count != command_num)
                {
                    // write stdout to the pipe
                    dup2(fd[1], STDOUT_FILENO);
                    close(fd[1]);
                }

                // use execvp() to run the commmand
                execvp(filename, argv);

                // exec didn't work, so an error must have been occurred
                cerr << strerror(errno) << endl;
                delete[] argv;
                return EXIT_FAILURE;
            }

            // wait for the child process to complete
            int status;
            waitpid(child, &status, 0);

            // close the current pipe write fd
            close(fd[1]);
            in_fd = fd[0];
            count += 1;
        }

        // // read out the pipe
        // char buffer[BUF_SIZ];
        // int count = read(in_fd, buffer, BUF_SIZ);
        // buffer[count] = '\0';
        // if (count > 0)
        // {
        //     fprintf(stdout, "%s", buffer);
        // }
        close(in_fd);

        cout << "$ ";
    }
    return EXIT_SUCCESS;
}
