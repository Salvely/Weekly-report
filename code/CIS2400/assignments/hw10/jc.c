#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "compile.h"

int main(int argc, char* argv[])
{
    if(argc < 3) {
        fprintf(stderr, "Usage: ./jc <output_file> <input_file> ...\n");
        exit(EXIT_FAILURE);
    }
    bool success;
    FILE *input;
    FILE *token_out = fopen("token.txt", "a+");
    for (int i = 2; i < argc; i++)
    {
        input = fopen(argv[i], "r");
        write_token(input, token_out);
    }
    input = fopen("token.txt", "r");
    FILE *output = fopen(argv[1], "w+");
    // // TODO: implement compile() function in compile.c, input = token, output = asm
    // success = compile(input,output);
    // if(success) {
    //     exit(EXIT_SUCCESS);
    // }
    exit(EXIT_FAILURE);
}