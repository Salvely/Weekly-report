#include "loader.h"
#include <endian.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

int sum = 0;

bool store_inst(FILE *fp)
{
    while(true) {
        // get the first byte and judge it
        uint16_t section;
        size_t bytes = fread(&section, 2, 1, fp);
        if (bytes != 1)
        {
            fprintf(stdout,"Could read no more instructions from the file!\n");
            return true;
        }

        section = htons(section);
        printf("section: %x\n", section);

        uint16_t addr; // the starting address
        uint16_t n; // the number of integers
        uint16_t line;
        uint16_t file_index;

        // read other bytes according to the section
        switch (section)
        {
            // code segment or data segment
            case 0xcade: case 0xdada:
            {
                // read the address in
                bytes = fread(&addr, 2, 1, fp);
                if(bytes != 1) {
                    fprintf(stderr, "The code/data segment address invalid!\n");
                    return false;
                }
                addr = htons(addr);
                
                // read the number of words in
                bytes = fread(&n, 2, 1, fp);
                if(bytes != 1) {
                    fprintf(stderr, "The code/data segment n invalid!\n");
                    return false;
                }
                n = htons(n);
                sum += n;

                // write the next n bytes to the array(remember to transform byte order)
                for (int i = 0; i < n; i++) {
                    uint16_t word;
                    // read the words
                    bytes = fread(&word, 2, 1, fp);
                    if(bytes != 1) {
                        fprintf(stderr, "Could not read the number of words.\n");
                        return false;
                    }
                    // transform into big endian byte order
                    word = htons(word);
                    // store it in the array
                    inst_array[addr + i] = word;
                }
            }
            break;
            // Symbol
            case 0xc3b7:
            {
                // read the address in
                bytes = fread(&addr, 2, 1, fp);
                if(bytes != 1) {
                    fprintf(stderr, "The code segment address invalid!\n");
                    return false;
                }
                addr = htons(addr);
                
                // read the number of bytes in
                bytes = fread(&n, 2, 1, fp);
                if(bytes != 1) {
                    fprintf(stderr, "The code segment n invalid!\n");
                    return false;
                }
                n = htons(n);

                // write the next n bytes to the array(remember to transform byte order)
                for (int i = 0; i < n; i++) {
                    uint8_t byte;
                    // read the bytes
                    bytes = fread(&byte, 1, 1, fp);
                    if(bytes != 1) {
                        fprintf(stderr, "Could not read the number of bytes.\n");
                        return false;
                    }
                }
            }
            break;
            // Filename
            case 0xf17e:
            {   
                // read the number of bytes in
                bytes = fread(&n, 2, 1, fp);
                if(bytes != 1) {
                    fprintf(stderr, "The code segment n invalid!\n");
                    return false;
                }
                n = htons(n);

                // write the next n bytes to the array(remember to transform byte order)
                for (int i = 0; i < n; i++) {
                    uint8_t byte;
                    // read the bytes
                    bytes = fread(&byte, 1, 1, fp);
                    if(bytes != 1) {
                        fprintf(stderr, "Could not read the number of bytes.\n");
                        return false;
                    }
                }
            }
            break;
            // Line Numbers
            case 0x715e:
            {
                // read the address in
                bytes = fread(&addr, 2, 1, fp);
                if(bytes != 1) {
                    fprintf(stderr, "The code/data segment address invalid!\n");
                    return false;
                }
                addr = htons(addr);
                
                // read the number of words in
                bytes = fread(&n, 2, 1, fp);
                if(bytes != 1) {
                    fprintf(stderr, "The code/data segment n invalid!\n");
                    return false;
                }
                n = htons(n);

                // write the next n bytes to the array(remember to transform byte order)
                uint16_t word;
                // read the words
                bytes = fread(&word, 2, 1, fp);
                if(bytes != 1) {
                    fprintf(stderr, "Could not read the number of words.\n");
                    return false;
                }
                // transform into big endian byte order
                word = htons(word);
            }
            break;
            default:
                break;
        } 
    }
}

void print_array()
{
    for (int i = 0; i < 65535; i++) {
        if(inst_array[i] != 0) {
            printf("%d: %04x\n", i, inst_array[i]);
        }
    }
}