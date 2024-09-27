#include <stdio.h>
#include <stdlib.h>
#include "loader.h"
#include "decode.h"

int main(int argc, char* argv[])
{
    if(argc < 3) {
        fprintf(stderr, "Usage: ./disas [output_filename] [object_file]...\n");
        exit(EXIT_FAILURE);
    }
    FILE *input;
    // for each file, write the object file to the array
    for (int i = 2; i < argc; i++) {
        input = fopen(argv[i], "r+");
        if(input == NULL) {
            fprintf(stderr, "Input File does not exists!\n");
            exit(EXIT_FAILURE);
        }
        bool success = store_inst(input);
        if(!success) {
            fprintf(stderr, "Could not store instructions in input file %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }
    print_array();
    // write output to a file
    FILE *output;
    output = fopen(argv[1], "w+");
    if(output == NULL) {
        fprintf(stderr, "Output File does not exists!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 65535; i++)
    {
        if(inst_array[i] != 0) {
            INSTR inst = decode_instr(inst_array[i]);
            print_instr(output, inst, i);            
        }

    }
    exit(EXIT_SUCCESS);
}