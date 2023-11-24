#ifndef __LOADER_H__
#define __LOADER_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

extern int position;
uint16_t inst_array[65536];

// store instruction in this file into the inst_array
bool store_inst(FILE *fp);

void print_array();
#endif