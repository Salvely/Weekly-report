#include "./decoder.h"

#include <stdio.h>  // for printf

#define UNDEFINED -1

// Simple program that allows you to compile to an executable
// and do some simple tests on decode_signals.
//
// Please feel free to modify as you wish
int main() {
  // create a INSTR that represent ADD R0, R1, #7
  INSTR instr;
  instr.type = ADDI;
  instr.Rd = 0;
  instr.Rs = 1;
  instr.Rt = UNDEFINED;
  instr.immediate = 7;

  // put the instr above into decode_signals
  // and get the results
  signals results = decode_signals(instr);

  // start printing out the results
  print_type(instr.type);
  printf("PCMux.CTL: %d\n", results.PCMuxCTL);
  
  return 0;
}

