disas: disas.c decode.o loader.o
	gcc -Wall -g -o disas $^

decode.o: decode.c decode.h
	gcc -c decode.c -g -o $@

loader.o: loader.c loader.h
	gcc -c loader.c -g -o $@

clean:
	rm -rf *.o disas