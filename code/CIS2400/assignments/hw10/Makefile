CC=gcc
CFLAGS=-Wall -g
jc: jc.c token.o
	$(CC) $(CFLAGS) $^ -o $@

# compile.o: compile.h compile.c
# 	$(CC) -c $(CFLAGS) $^ $@

token.o: token.c token.h 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm *.txt