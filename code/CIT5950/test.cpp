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

#include <sys/types.h> // for pid_t
#include <sys/wait.h>  // for wait(), waitpid(), etc.
#include <unistd.h>    // for fork()

#include <boost/algorithm/string.hpp>
#include <cstdlib> // for exit(), EXIT_SUCCESS, and EXIT_FAILURE
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define BUF_SIZ 1000

int main() {
  string s;
  cout << "$ ";
  while (getline(std::cin, s)) {
    if (s == "exit") {
      return EXIT_SUCCESS;
    }

    // initialize a pipe
    int fd[2];
    if (pipe(fd) == -1) {
      perror("pipe creation failed!");
      return EXIT_FAILURE;
    }

    // split the command into multiple parts
    vector<string> tokens;
    boost::algorithm::split(tokens, s, boost::is_any_of("|"),
                            boost::token_compress_on);
    for (auto &command : tokens) {
      // prepare to run the current command

      // get the current command
      boost::algorithm::trim(command);
      // split the command into an array of args
      vector<string> args;
      boost::algorithm::split(args, command, boost::is_any_of(" "),
                              boost::token_compress_on);
      int argc = args.size();
      if (argc < 1) {
        cerr << "We need a command!" << endl;
        return EXIT_FAILURE;
      }

      // run the current command
      pid_t child = fork();
      if (child == 0) {
        // setup the file name and input arguments
        const char *filename = args[0].c_str();
        char **argv = new char *[argc + 1];
        for (int i = 0; i < argc; i++) {
          string args_str = args[i];
          argv[i] = new char[10];
          strcpy(argv[i], args_str.c_str());
        }
        argv[argc] = nullptr;

        close(STDIN_FILENO);
        // write the pipe value into stdin
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        close(STDOUT_FILENO);
        // write stdout to the pipe
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

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
    }
    // read out the pipe
    char *buffer = new char[BUF_SIZ];
    int count = read(fd[0], buffer, BUF_SIZ);
    if (count > 0) {
      fprintf(stdout, "%s", buffer);
    }

    delete buffer;

    close(fd[0]);
    close(fd[1]);
    cout << "$ ";
  }
  return EXIT_SUCCESS;
}
