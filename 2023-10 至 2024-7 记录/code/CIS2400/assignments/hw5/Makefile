#
# Makefile that builds the decoder object file and decoder_main executable for testing
# 

main: main.c decoder.h decoder.o
	gcc -g -Wall -std=c11 -o main main.c decoder.o

decoder.o: decoder.c decoder.h
	gcc -g -Wall -std=c11 -c decoder.c

clean:
	rm -f *.o main *~


