#include "./decoder.h"
#include <string.h> // for memset
#include <stdio.h> // for printf

#include <stdio.h>

// This is the only function you need to modify for this assignment
//
// Given an instruction, return the appropriate control signals for that instruction.
// Note that you do not need to handle every instruction for this assignment.
// ILLEGAL_INSN is handled for you, but you must handle instructions of the type:
// - ADDI
// - BRnz
// - JSR
// - CMPIU
// - LDR
signals decode_signals(INSTR instr) {
  // create sruct to store result
  signals res;

  // default set every signal to be garbage
  // This means you need to be sure to set every value yourself
  memset(&res, 0x7E, sizeof(res)); 

  if (instr.type == ILLEGAL_INSN) {
    res.PCMuxCTL = ANY_SIGNAL; 
    res.rsMuxCTL = ANY_SIGNAL; 
    res.rtMuxCTL = ANY_SIGNAL; 
    res.rdMuxCTL = ANY_SIGNAL; 
    res.regFileWE = ANY_SIGNAL; 
    res.regInputMuxCTL = ANY_SIGNAL; 
    res.NZPWE = ANY_SIGNAL; 
    res.DATAWE = ANY_SIGNAL; 
    res.PrivilegeCTL = ANY_SIGNAL; 
    res.ALUInputMuxCTL = ANY_SIGNAL; 
    res.ALUCTL = ANY_SIGNAL; 
    return res;
  }

  // - ADDI
  if(instr.type == ADDI) {
    res.PCMuxCTL = 1;
    res.rsMuxCTL = 0;
    res.rdMuxCTL = 0;
    res.regFileWE = 1;
    res.regInputMuxCTL = 0;
    res.NZPWE = 1;
    res.DATAWE = 0;
    res.PrivilegeCTL = 2;
    res.ALUInputMuxCTL = 1;
    res.ALUCTL = 6;

    res.rtMuxCTL = ANY_SIGNAL;
  }
  // - JSR
  else if(instr.type == JSR) {
    res.rsMuxCTL = ANY_SIGNAL;
    res.rtMuxCTL = ANY_SIGNAL;
    res.rdMuxCTL = ANY_SIGNAL;
    res.regFileWE = 0;
    res.ALUCTL = ANY_SIGNAL;
    res.ALUInputMuxCTL = ANY_SIGNAL;
    res.DATAWE = 0;
    res.regInputMuxCTL = ANY_SIGNAL;
    res.NZPWE = 0;

    res.PrivilegeCTL = 2;
    res.PCMuxCTL = 5;
  }
  // - BRnz
  else if(instr.type == BRnz) {
    res.rsMuxCTL = ANY_SIGNAL;
    res.rtMuxCTL = ANY_SIGNAL;
    res.rdMuxCTL = ANY_SIGNAL;
    res.regFileWE = 0;
    res.ALUCTL = ANY_SIGNAL;
    res.DATAWE = 0;
    res.ALUInputMuxCTL = ANY_SIGNAL;
    res.regInputMuxCTL = ANY_SIGNAL;
    res.NZPWE = 0;

    res.PrivilegeCTL = 2;
    res.PCMuxCTL = 0;
  }
  // - CMPIU
  else if(instr.type == CMPU) {
    res.rdMuxCTL = ANY_SIGNAL;
    res.regFileWE = 0;
    res.DATAWE = 0;
    res.PrivilegeCTL = 2;

    res.rsMuxCTL = 2;
    res.rtMuxCTL = 0;
    res.ALUInputMuxCTL = 0;
    res.ALUCTL = 2;
    res.regInputMuxCTL = 0;
    res.NZPWE = 1;
    res.PCMuxCTL = 0;
  }
  // - STR
  else if(instr.type == STR) {
    res.rdMuxCTL = ANY_SIGNAL;
    res.DATAWE = 0;
    res.NZPWE = 0;

    res.rsMuxCTL = 0;
    res.rtMuxCTL = 1;
    res.regFileWE = 1;
    res.ALUCTL = 6;
    res.ALUInputMuxCTL = 1;
    res.regInputMuxCTL = 1;
    res.PrivilegeCTL = 2;
    res.PCMuxCTL = 0;
  }
  else if(instr.type == LDR) {
    res.rtMuxCTL = ANY_SIGNAL;
    res.DATAWE = 0;
    res.NZPWE = 0;

    res.rsMuxCTL = 0;
    res.rdMuxCTL = 0;
    res.regFileWE = 1;
    res.ALUCTL = 6;
    res.ALUInputMuxCTL = 1;
    res.regInputMuxCTL = 1;
    res.PrivilegeCTL = 2;
    res.PCMuxCTL = 0;
  }

  // return resulting control signals
  return res;
}


// Implementation of helper funtcion that may be useful for debugging
// You should not modify this function, nor do you need to understand how it works
// If you do want to know how this works, we left some comments but it may be easier
// to understand once we cover C in class.
//
// Given an INSTR_TYPE, prints out the corresponding string for that type.
// This is provided for debugging purposes, you should not modify the method
void print_type(INSTR_TYPE type) {
  // declares an array of C-strings containing the string of every
  // LC4 instruction type. This array exists in global memory
  // and is generated exactly once.
  static char* type_strings[] = {
    "ILLEGAL INSN",
    "NOP", "BRp", "BRz", "BRzp", "BRn", "BRnp", "BRnz", "BRnzp",
    "ADD", "MUL", "SUB", "DIV", "ADDI",
    "MOD",
    "AND", "NOT", "OR", "XOR", "ANDI",
    "LDR", "STR",
    "CONST", "HICONST",
    "CMP", "CMPU", "CMPI", "CMPIU",
    "SLL", "SRA", "SRL",
    "JSRR", "JSR",
    "JMPR", "JMP",
    "TRAP", "RTI"
  };

  // Note that an ENUM variable instance is internally implemented as a
  // integer variable. The value of that integer corresponds with the order in which
  // the possible enum values are declared. So ILLEGAL_INSN is represented as the integer 0
  // and the enum value NOP is implemented as the integer 1.
  printf("%s\n", type_strings[type]);
}
