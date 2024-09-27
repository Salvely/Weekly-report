/*
 * decode.h
 */

#include <stdint.h> // for uint16_t
#include <stdio.h>
// Defines a new enumerated type 'INSTR_TYPE'
// which is used to identify the different types of instructions in LC4
// Each of the listed values e.g. ILLEGAL_INSTR, NOP, BRp, ... are
// possible values of the INSTR_TYPE.
//
// Note that there are the INSTR types ADD and ADDI to distinguish
// the instructions the ADD instruction that uses three registers (ADD)
// and to the instruciton that uses two registers and an integer immediate
// (ADDI) The same applies to AND and ANDI.
typedef enum {
  ILLEGAL_INSTR,
  NOP,
  BRp,
  BRz,
  BRzp,
  BRn,
  BRnp,
  BRnz,
  BRnzp,
  ADD,
  MUL,
  SUB,
  DIV,
  ADDI,
  MOD,
  AND,
  NOT,
  OR,
  XOR,
  ANDI,
  LDR,
  STR,
  CONST,
  HICONST,
  CMP,
  CMPU,
  CMPI,
  CMPIU,
  SLL,
  SRA,
  SRL,
  JSRR,
  JSR,
  JMPR,
  JMP,
  TRAP,
  RTI
} INSTR_TYPE;
          
// Defines a new data type called "INSTR" which provides a more convenient
// way to parse the "Mnemonic" or "Text" version of an instruction.
// Eg. instead of having to parse the string "JSRR R3":
//   - the type is set to the enum value JSRR
//   - Rs is set to the integer 3
//   - Rd, Rt, and immediate can contain any value since they are not
//     specified in the "text version" of the instruction.
typedef struct {
  INSTR_TYPE type;     // Type of the instruction
  int Rd, Rs, Rt;      // Register fields
  short int immediate; // Immediate field of instruction
} INSTR;

// decode_instr : This function takes as input an unsigned 16 bit pattern and
// decodes that into an INSTR structure that breaks out the various instruction
// components.
//
// If an INSTR doesn't use some fields, the values for those fields can be
// anything. For example: JMP doesn't use an Rd, Rs, or Rt so those fields in
// the returned struct can be anything.
//
// If the 16-bit pattern doesn't decode to a valid instruction, the returned
// INSTR struct will have it's type set to ILLEGAL_INSTR
//
// Arguments:
// - instr: the 16-bit pattern to be interpreted into an INSTR
//
// Returns:
// - The INSTR structure representing the interpreted 16 bits
INSTR decode_instr(uint16_t instr);

// Prints a readable version of the instruction out to the specified file
//
// The printed out string should resemble the instructions as they should appear
// in a valid ASM file.
// This means:
// - If there are multiple "arguments" to the insn (registers/immediate used)
//   there should be a command and a space between each one.
// - If there is an immediate, then it should print a '#' before printing the
//   immedaite value
// - Instructions that have integer immediate variantes like ADDI and ANDI
//   should be printed as ADD and AND (as they show up in normal LC4 code)
//
// For example, some potential outputs are:
// - "JMP #7"
// - "ADD R5, R6, #-1"
//
// Arguments:
// - output: the file we are printing the intruction to
// - instr: the instruction we want to print to the output file
void print_instr(FILE *out_file, INSTR instr, int addr);
