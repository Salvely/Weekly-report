#include "decode.h"
#include "loader.h"
#include <stdio.h>

#define STR(x) #x

int line = 0;
char *type_name[] = {"ILLEGAL_INSTR",
                     "NOP",
                     "BRp",
                     "BRz",
                     "BRzp",
                     "BRn",
                     "BRnp",
                     "BRnz",
                     "BRnzp",
                     "ADD",
                     "MUL",
                     "SUB",
                     "DIV",
                     "ADDI",
                     "MOD",
                     "AND",
                     "NOT",
                     "OR",
                     "XOR",
                     "ANDI",
                     "LDR",
                     "STR",
                     "CONST",
                     "HICONST",
                     "CMP",
                     "CMPU",
                     "CMPI",
                     "CMPIU",
                     "SLL",
                     "SRA",
                     "SRL",
                     "JSRR",
                     "JSR",
                     "JMPR",
                     "JMP",
                     "TRAP",
                     "RTI"};
INSTR decode_instr(uint16_t instr)
{
    INSTR result;
    result.type = ILLEGAL_INSTR;
    result.Rd = 255;
    result.Rs = 255;
    result.Rt = 255;
    result.immediate = -32768;

    uint16_t opcode = (instr >> 12) & 0xf;
    switch (opcode) {
        case 0b0000:
            {
                unsigned char sub_code = (instr >> 9) & 0b111;
                int imm = instr & 0x1ff;
                switch (sub_code)
                {
                    case 0:
                        result.type = NOP;
                        break;
                    case 1:
                        result.type = BRp;
                        break;
                    case 2:
                        result.type = BRz;
                        break;
                    case 3:
                        result.type = BRzp;
                        break;
                    case 4:
                        result.type = BRn;
                        break;
                    case 5:
                        result.type = BRnp;
                        break;
                    case 6:
                        result.type = BRnz;
                        break;
                    case 7:
                        result.type = BRnzp;
                        break;
                }
                if(sub_code != 0) {
                    result.immediate = imm;
                    if(result.immediate > ((1 << 8) - 1)) {
                        result.immediate -= (1 << 9);
                    }
                }
            }
            break;
        case 0b0001:
            {
                unsigned char sub_code = (instr >> 3) & 0x07;
                switch (sub_code)
                {
                    case 0:
                        result.type = ADD;
                        break;
                    case 1:
                        result.type = MUL;
                        break;
                    case 2:
                        result.type = SUB;
                        break;
                    case 3:
                        result.type = DIV;
                        break;
                    default:
                        result.type = ADD;
                        break;
                }
                result.Rs = (instr >> 6) & 0x7;
                result.Rd = (instr >> 9) & 0x7;
                if(sub_code <= 3) {
                    result.Rt = instr & 0x7;
                }
                else {
                    result.immediate = instr & 31;
                    
                    if (result.immediate > ((1 << 4) - 1))
                    {
                        result.immediate -= (1 << 5);
                    }
                }
            }
            break;
        case 0b0101:
            {
                unsigned char sub_code = (instr >> 3) & 0x07;
                switch (sub_code)
                {
                    case 0:
                        result.type = AND;
                        break;
                    case 1:
                        result.type = NOT;
                        break;
                    case 2:
                        result.type = OR;
                        break;
                    case 3:
                        result.type = XOR;
                        break;
                    default:
                        result.type = ANDI;
                        break;
                }
                result.Rs = (instr >> 6) & 0x7;
                result.Rd = (instr >> 9) & 0x7;
                if(sub_code <= 3) {
                    if(result.type != NOT)
                        result.Rt = instr & 0x7;
                }
                else {
                    result.immediate = instr & 31;

                    if (result.immediate > ((1 << 4) - 1))
                    {
                        result.immediate -= (1 << 5);
                    }
                }
            }
            break;
        case 0b0110:
            {
                result.type = LDR;
                result.Rs = (instr >> 6) & 0x7;
                result.Rd = (instr >> 9) & 0x7;
                result.immediate = instr & 63;
                if (result.immediate > ((1 << 5) - 1))
                {
                    result.immediate -= (1 << 6);
                }
            }
            break;
        case 0b0111:
            {
                result.type = STR;
                result.Rs = (instr >> 6) & 0x7;
                result.Rt = (instr >> 9) & 0x7;
                result.immediate = instr & 63;
                if (result.immediate > ((1 << 5) - 1))
                {
                    result.immediate -= (1 << 6);
                }
            }
            break;
        case 0b1001:
            {
                result.type = CONST;
                result.Rd = (instr >> 9) & 0x7;
                result.immediate = instr & 0b111111111;
                if (result.immediate > ((1 << 8) - 1))
                {
                    result.immediate -= (1 << 9);
                }
                return result;
            }
            break;
        case 0b1101:
            {
                result.type = HICONST;
                result.Rd = (instr >> 9) & 0x7;
                result.immediate = instr & 0b111111111;
                if (result.immediate > ((1 << 8) - 1))
                {
                    result.immediate -= (1 << 8);
                }
            }
            break;
        case 0b0010:
            {
                result.Rs = (instr >> 9) & 0b111;
                unsigned char sub_code = (instr >> 7) & 0b11;
                switch (sub_code)
                {
                case 0:
                    result.type = CMP;
                    result.Rt = instr & 0b111;
                    break;
                case 1:
                    result.type = CMPU;
                    result.Rt = instr & 0b111;
                    break;
                case 2:
                    result.type = CMPI;
                    result.immediate = instr & 0b1111111;
                    if (result.immediate > ((1 << 6) - 1))
                    {
                        result.immediate -= (1 << 7);
                    }
                    break;
                case 3:
                    result.type = CMPIU;
                    result.immediate = instr & 0b1111111;
                    if (result.immediate > ((1 << 7) - 1))
                    {
                        result.immediate -= (1 << 7);
                    }
                    break;
                }
            }
            break;
        case 0b1010:
            {
                unsigned char sub_code = (instr >> 4) & 0b11;
                switch (sub_code)
                {
                    case 0:
                        result.type = SLL;
                        break;
                    case 1:
                        result.type = SRA;
                        break;
                    case 2:
                        result.type = SRL;
                        break;
                    case 3:
                        result.type = MOD;
                        break;
                }
                result.Rs = (instr >> 6) & 0x7;
                result.Rd = (instr >> 9) & 0x7;
                if(sub_code < 3) {
                    result.immediate = instr & 0xf;
                    if (result.immediate > ((1 << 4) - 1))
                    {
                        result.immediate -= (1 << 4);
                    }
                }
                else {
                    result.Rt = instr & 0x7;
                }
            }
            break;
        case 0b0100:
            {
                unsigned sub_code = (instr >> 11) & 0x1;
                switch (sub_code) {
                    case 0:
                        result.type = JSRR;
                        result.Rs = (instr >> 6) & 0b111;
                        break;
                    case 1:
                        result.type = JSR;
                        result.immediate = instr & 0x7ff;
                        if (result.immediate > ((1 << 10) - 1))
                        {
                            result.immediate -= (1 << 10);
                        }
                        break;
                }
            }
            break;
        case 0b1100:
            {
                unsigned sub_code = (instr >> 11) & 0x1;
                switch (sub_code) {
                    case 0:
                        result.type = JMPR;
                        result.Rs = (instr >> 6) & 0b111;
                        break;
                    case 1:
                        result.type = JMP;
                        result.immediate = instr & 0x7ff;
                        if (result.immediate > ((1 << 10) - 1))
                        {
                            result.immediate -= (1 << 11);
                        }                        
                        break;
                }
            }
            break;
        case 0b1111:
            {
                result.type = TRAP;
                result.immediate = instr & 0xff;
                if (result.immediate > ((1 << 8) - 1))
                {
                    result.immediate -= (1 << 8);
                }                
            }
            break;
        case 0b1000:
            {
                result.type = RTI;
            }
            break;
        default:
            result.type = ILLEGAL_INSTR;
            break;
        }
    return result;
}

void print_instr(FILE *out_file, INSTR instr, int addr)
{
    if(line > 0) {
        fprintf(out_file, "\n");
    }
    line += 1;
    if (instr.type == ILLEGAL_INSTR)
    {
        fprintf(out_file, "%04X : %04X", addr, inst_array[addr]);
    }
    else {
        fprintf(out_file, "%04X : %04X", addr, inst_array[addr]);
        INSTR_TYPE type = instr.type;
        if(instr.type != NOP)
            fprintf(out_file, " -> %s ", type_name[instr.type]);

        // BRzp <imm>
        if(instr.Rs == 255 && instr.Rt == 255 && instr.Rd == 255 && instr.immediate != -32768) {
            fprintf(out_file, "#%d", instr.immediate);
        }
        // ADD Rd, Rs(, IMM|, Rt) | 
        else if(instr.Rd != 255 && instr.Rs != 255) {
            fprintf(out_file, "R%d, R%d", instr.Rd,instr.Rs);
            if(instr.Rt != 255) {
                fprintf(out_file, ", R%d", instr.Rt);
            }
            else if(instr.immediate != -32768) {
                fprintf(out_file, ", #%d", instr.immediate);
            }
        }
        // CONST Rd, IMM9
        else if(instr.Rd != 255 && instr.immediate != -32768 && instr.Rt == 255 && instr.Rs == 255) {
            fprintf(out_file,"R%d, #%d", instr.Rd, instr.immediate);
        }
        // JSR, JMP, TRAP
        else if(instr.immediate != -32768 && instr.Rd == 255 && instr.Rt == 255 && instr.Rs == 255) {
            fprintf(out_file, "#%d", instr.immediate);
        }
        else if(instr.Rs != 255) {
            // JMPR, JSRR
            if(instr.Rd == 255 && instr.Rt == 255 && instr.immediate == -32768) {
                fprintf(out_file,"R%d", instr.Rs);
            }
            else if(instr.Rt != 255 && instr.immediate == -32768) {
                fprintf(out_file, "R%d, R%d", instr.Rs, instr.Rt);
            }
            else if(instr.Rt == 255 && instr.immediate != -32768) {
                fprintf(out_file, "R%d, #%d", instr.Rs, instr.immediate);
            }
            else {
                fprintf(out_file, "R%d, R%d, #%d", instr.Rt, instr.Rs, instr.immediate);
            }
        }
    }
}
