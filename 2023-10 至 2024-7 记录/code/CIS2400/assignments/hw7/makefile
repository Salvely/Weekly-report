# Copyright ©2022 Travis McGaha.  All rights reserved.  Permission is
# hereby granted to students registered for University of Pennsylvania
# CIS 2400 for use solely during Fall Semester 2022 for purposes of
# the course.  No other use, copying, distribution, or modification
# is permitted without prior written consent. Copyrights for
# third-party components of this work must be honored.  Instructors
# interested in reusing these course materials should contact the
# author.

# compile everything; this is the default rule that fires if a user
# just types "make" in the same directory as this Makefile
all: test_suite rpn

test_suite: test_suite.c test_deque.o Deque.o
	gcc -g -Wall -std=c11 -o test_suite test_suite.c test_deque.o Deque.o

rpn: rpn.c Deque.o rat_num.h
	gcc -g -Wall -std=c11 -o rpn rpn.c Deque.o

test_deque.o: test_deque.c test_deque.h rat_num.h
	gcc -g -Wall -std=c11 -c test_deque.c

Deque.o: Deque.c Deque.h rat_num.h
	gcc -g -Wall -std=c11 -c Deque.c

clean:
	rm -f *.o *~ test_suite rpn
