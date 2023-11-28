CC=gcc
CFLAGS=-Wall -g
jc: jc.c token.o compile.o
	$(CC) $(CFLAGS) $^ -o $@

compile.o: compile.c compile.h 
	$(CC) $(CFLAGS) -c $<

token.o: token.c token.h 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm *.txt