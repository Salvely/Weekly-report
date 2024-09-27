#ifndef DECODER_H_
#define DECODER_H_

// This file contains the declarations of the functions used in this assignment
// and the definitions for various types and constants used in this assignment
//
// ****************************************************************************
// ********************* DO NOT MODIFY THIS FILE ******************************
// ****************************************************************************


// Defines a new enumerated type 'INSTR_TYPE'
// which is used to identify the different types of instructions in LC4
// Each of the listed values e.g. ILLEGAL_INSN, NOP, BRp, ... are
// possible values of the INSTR_TYPE.
//
// Note that there are the INSTR types ADD and ADDI to distinguish
// the instructions the ADD instruction that uses three registers (ADD)
// and to the instruciton that uses two registers and an integer immediate (ADDI)
// The same applies to AND and ANDI.
typedef enum {ILLEGAL_INSN,
	      NOP, BRp, BRz, BRzp, BRn, BRnp, BRnz, BRnzp,
	      ADD, MUL, SUB, DIV, ADDI,
	      MOD,
	      AND, NOT, OR, XOR, ANDI,
	      LDR, STR,
	      CONST, HICONST,
	      CMP, CMPU, CMPI, CMPIU,
	      SLL, SRA, SRL,
	      JSRR, JSR,
	      JMPR, JMP,
	      TRAP, RTI} INSTR_TYPE;

// defines a constant "variable" that can be later used
// to indicate that any signal is ok for that signal value
#define ANY_SIGNAL -1

// Defines a new data type called "signals" which
// represents a collection of all control signals.
//
// Note that this is a struct type which can be thought of as
// similiar to an object type, but it can only contain data fields
// and no object methods. 
typedef struct signals_st {
  int PCMuxCTL;
  int rsMuxCTL;
  int rtMuxCTL;
  int rdMuxCTL;
  int regFileWE;
  int regInputMuxCTL;
  int NZPWE;
  int DATAWE;
  int PrivilegeCTL;
  int ALUInputMuxCTL;
  int ALUCTL;
} signals;

// Defines a new data type called "INSTR" which provides a more convenient
// way to parse the "Mnemonic" or "Text" version of an instruction.
// Eg. instead of having to parse the string "JSRR R3":
//   - the type is set to the enum value JSRR
//   - Rs is set to the integer 3
//   - Rd, Rt, and immediate can contain any value since they are not
//     specified in the "text version" of the instruction.
// Note that this is a struct type which can be thought of as
// similiar to an object type, but it can only contain data fields
// and no object methods. 
typedef struct {
  INSTR_TYPE type;      // Type of the instruction
  int Rd, Rs, Rt;       // Register fields
  short int immediate;  // Immediate field of instruction 
}  INSTR;


// Given an INSTR_TYPE, prints out the corresponding string for that type.
// This is provided for debugging purposes, you should not modify the method
void print_type(INSTR_TYPE type);

// This is the method you are partially implementing for this homework.
// Given an instruction, return the appropriate control signals for that instruction.
// Note that you do not need to handle every instruction for this assignment.
// ILLEGAL_INSN is handled for you, but you must handle instructions of the type:
// - ADDI
// - JSR
// - BRnz
// - CMPU
// - STR
signals decode_signals(INSTR instr);

#endif  // DECODER_H_
