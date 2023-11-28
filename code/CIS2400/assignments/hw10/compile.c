#include "compile.h"
#include "token.h"
#include <stdlib.h>
#include <string.h>

unsigned short r5 = 0x7ffe; // frame pointer
unsigned short r6 = 0x7ffe; // stack pointer
int label_num = 0; // the label number

bool compile(FILE *input, FILE *output)
{
    token t;
    while(read_token(input, &t)) {
        bool success = false;
        if (t.type == LITERAL)
        {
            success = process_literal(&t,output);
        }
        else if(t.type == PLUS || t.type == MINUS || t.type == MUL || t.type == DIV || t.type == MOD) {
            success = arithmetic(&t,output);
        }
        else if(t.type == LT || t.type == LE || t.type == EQ || t.type == GE || t.type ==GT) {
            success = comparison(&t,output);
        }
        else if(t.type == AND || t.type == OR || t.type == NOT) {
            success = logical(&t,output);
        }
        else if(t.type == DROP || t.type == DUP || t.type == SWAP || t.type == ROT) {
            success = stack_operation(&t,output);
        }
        else if(t.type == IF) {
            success = process_if(&t,input,output);
        }
        else if(t.type == WHILE) {
            success = process_while(&t,input,output);
        }
        else if(t.type == DEFUN) {
            success = function_define(&t,output);
        }
        else if(t.type == RETURN) {
            success = function_return(&t,output);
        }
        else if(t.type == IDENT) {
            success = function_call(&t,output);
        }
        if(!success) {
            return false;
        }
    }
    return true;
}

bool read_token(FILE *input, token *token_output)
{
    char str[MAX_TOKEN_LENGTH+10];
    // read the formatted token string into str
    if(fgets(str, MAX_TOKEN_LENGTH + 10, input) == NULL) {
        return false;
    }

    // parse the token string: "token_str token_type [literal(hex)]/[arg(decimal)]"
    char *delim = " ";
    // get the token string
    strcpy(token_output->str, strtok(str, delim));
    // get the token type
    token_output->type = atoi(strtok(NULL, delim));
    // get the literal value or arg number
    char *val = strtok(NULL, delim);
    // if type == LITERAL
    if(token_output->type == LITERAL) {
        token_output->literal_value = atoi(val);
    }
    // if type == ARG
    else if(token_output->type == ARG) {
        token_output->arg_no = atoi(val);
    }

    return true;
}

bool process_literal(token *input, FILE* output)
{
    // literals are pushed onto the stack(where is the stack base and the stack pointer)
    // store the literal in a register first(R0)
    fprintf(output, "   CONST R0, %#x\n", input->literal_value);
    fprintf(output, "   STR R0, R6, #0\n");
    fprintf(output, "   SUB R6, R6, #2\n");
    return true;
}

bool arithmetic(token *input, FILE* output)
{
    // pop the 2 value from stack(store in R0 and R1)
    fprintf(output, "   ADD R6, R6, #2\n");
    fprintf(output, "   LDR R0, R6, #0\n");
    fprintf(output, "   ADD R6, R6, #2\n");
    fprintf(output, "   LDR R1, R6, #0\n");
    // perform arithmetic on them(where to store the temporary result? R0)
    switch (input->type) {
        case PLUS:
            fprintf(output, "   ADD R0, R0, R1\n");
            break;
        case MINUS:
            fprintf(output, "   SUB R0, R0, R1\n");
            break;
        case MUL:
            fprintf(output, "   MUL R0, R0, R1\n");
            break;
        case DIV:
            fprintf(output, "   DIV R0, R0, R1\n");
            break;
        case MOD:
            fprintf(output, "   MOD R0, R0, R1\n");
            break;
        default:
            fprintf(stderr, "Arithmetic operator error!\n");
            return false;
    }

    // then push the result onto the stack
    fprintf(output, "   STR R0, R6, #0\n");
    fprintf(output, "   SUB R6, R6, #2\n");
    return true;
}

bool comparison(token *input, FILE* output)
{
    // pop the 2 value from stack(store in R0 and R1)
    fprintf(output, "   ADD R6, R6, #2\n");
    fprintf(output, "   LDR R0, R6, #0\n");
    fprintf(output, "   ADD R6, R6, #2\n");
    fprintf(output, "   LDR R1, R6, #0\n");
    // perform comparison on them(where to store the temporary result? R0)
    fprintf(output, "   CMP R0, R1\n");
    switch (input->type)
    {
    case LT: // <
        fprintf(output, "   Brn LT%d\n", label_num);
        fprintf(output, "   CONST R0, #0\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");        
        fprintf(output, "   JMP ENDLT%d\n", label_num);
        fprintf(output, "LT%d\n", label_num);
        fprintf(output, "   CONST R0, #1\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");
        fprintf(output, "ENDLT%d\n", label_num);
        break;
    case LE: // < || ==
        fprintf(output, "   Brnz LE%d\n", label_num);
        fprintf(output, "   CONST R0, #0\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");        
        fprintf(output, "   JMP ENDLE%d\n", label_num);
        fprintf(output, "LE%d\n", label_num);
        fprintf(output, "   CONST R0, #1\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");
        fprintf(output, "ENDLE%d\n", label_num);
        break;
    case EQ: // ==
        fprintf(output, "   Brz EQ%d\n", label_num);
        fprintf(output, "   CONST R0, #0\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");        
        fprintf(output, "   JMP ENDEQ%d\n", label_num);
        fprintf(output, "EQ%d\n", label_num);
        fprintf(output, "   CONST R0, #1\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");
        fprintf(output, "ENDEQ%d\n", label_num);
        break;
    case GE: // > || ==
        fprintf(output, "   Brzp GE%d\n", label_num);
        fprintf(output, "   CONST R0, #0\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");        
        fprintf(output, "   JMP ENDGE%d\n", label_num);
        fprintf(output, "GE%d\n", label_num);
        fprintf(output, "   CONST R0, #1\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");
        fprintf(output, "ENDGE%d\n", label_num);
        break;
    case GT: // >
        fprintf(output, "   Brp GT%d\n", label_num);
        fprintf(output, "   CONST R0, #0\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");        
        fprintf(output, "   JMP ENDGT%d\n", label_num);
        fprintf(output, "GT%d\n", label_num);
        fprintf(output, "   CONST R0, #1\n");
        fprintf(output, "   STR R0, R6, #0\n");
        fprintf(output, "   SUB R6, R6, #2\n");
        fprintf(output, "ENDGT%d\n", label_num);
        break;
    default:
        fprintf(stderr, "Comparison operator error!\n");
        return false;
    }
    label_num += 1;
    return true;
}

bool logical(token *input, FILE* output)
{
    // pop the 2 value from stack(store in R0 and R1)
    fprintf(output, "   ADD R6, R6, #2\n");
    fprintf(output, "   LDR R0, R6, #0\n");
    if(input->type != NOT) {
        fprintf(output, "   ADD R6, R6, #2\n");
        fprintf(output, "   LDR R1, R6, #0\n");
    }

    // perform arithmetic on them(where to store the temporary result? R0)
    switch (input->type) {
        case AND:
            fprintf(output, "   AND R0, R0, R1\n");
            break;
        case OR:
            fprintf(output, "   OR R0, R0, R1\n");
            break;
        case NOT:
            fprintf(output, "   NOT R0, R0\n");
            break;
        default:
            fprintf(stderr, "Logical operator error!\n");
            return false;
    }

    // then push the result onto the stack
    fprintf(output, "   STR R0, R6, #0\n");
    fprintf(output, "   SUB R6, R6, #2\n");
    return true;
}

bool stack_operation(token *input, FILE* output)
{
    // pop the 2 value from stack, perform stack operation on them(R0, R1, R2)
    // then push the result onto the stack
    fprintf(output, "   ADD R6, R6, #2\n");
    fprintf(output, "   LDR R0, R6, #0\n");
    if(input->type == SWAP || input->type == ROT) {
        fprintf(output, "   ADD R6, R6, #2\n");
        fprintf(output, "   LDR R1, R6, #0\n");
        if(input->type == ROT) {
            fprintf(output, "   ADD R6, R6, #2\n");
            fprintf(output, "   LDR R2, R6, #0\n");            
        }
    }
    
    // perform arithmetic on them(where to store the temporary result? R0)
    switch (input->type) {
        case DROP:
            break;
        case DUP:
            fprintf(output, "   STR R0, R6, #0\n");
            fprintf(output, "   SUB R6, R6, #2\n");
            break;
        case SWAP:
            fprintf(output, "   STR R0, R6, #0\n");
            fprintf(output, "   SUB R6, R6, #2\n");
            fprintf(output, "   STR R1, R6, #0\n");
            fprintf(output, "   SUB R6, R6, #2\n");
            break;
        case ROT:
            fprintf(output, "   STR R1, R6, #0\n");
            fprintf(output, "   SUB R6, R6, #2\n");
            fprintf(output, "   STR R0, R6, #0\n");
            fprintf(output, "   SUB R6, R6, #2\n");
            fprintf(output, "   STR R2, R6, #0\n");
            fprintf(output, "   SUB R6, R6, #2\n");
            break;
        default:
            fprintf(stderr, "Stack operator error!\n");
            return false;
    }
    
    // TODO: argN not yet implemented
    return false;
}

bool process_if(token *input_token, FILE* input, FILE* output)
{
    int label = label_num;
    // first pop the value from the stack
    fprintf(output, "   ADD R6, R6, #2\n");
    fprintf(output, "   LDR R0, R6, #0\n");
    // if R0 != 0, go to block A
    fprintf(output, "   Brnp BLOCKA%d\n",label);
    // else go to block B
    fprintf(output, "   Brz BLOCKB%d\n", label);
    // Code for BlockA
    fprintf(output, "BLOCKA%d\n", label);
    while(compile(input,output)) {}
    fprintf(output, "JMP ENDIF%d\n", label);
    // Code for BlockB
    fprintf(output, "BLOCKB%d\n", label);
    while(compile(input, output)) {}
    fprintf(output, "JMP ENDIF%d\n", label);
    fprintf(output, "ENDIF%d\n", label);
    label_num++;
    return true;
}

bool process_while(token *input_token, FILE* input, FILE* output)
{
    int label = label_num;
    fprintf(output, "LOOP%d\n", label);
    // first pop the value from the stack
    fprintf(output, "   ADD R6, R6, #2\n");
    fprintf(output, "   LDR R0, R6, #0\n");
    // check if it's zero
    fprintf(output, "   Brz ENDWHILE%d\n",label);
    while(compile(input, output)){}
    fprintf(output,"   JMP LOOP%d\n", label);
    fprintf(output, "ENDWHILE%d\n", label);
    return true;
}

bool function_define(token *input, FILE* output)
{
    return false;
}

bool function_return(token *input, FILE* output)
{
    return false;
}

bool function_call(token *input, FILE* output)
{
    return false;
}
