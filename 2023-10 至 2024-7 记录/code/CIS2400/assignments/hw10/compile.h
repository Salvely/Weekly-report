#ifndef __COMPILE_H__
#define __COMPILE_H__

#include <stdbool.h>
#include <stdio.h>
#include "token.h"

bool read_token(FILE *input, token* token_output);

bool process_literal(token *input, FILE* output);
bool arithmetic(token *input, FILE* output);
bool comparison(token *input, FILE* output);
bool logical(token *input, FILE* output);
bool stack_operation(token *input, FILE* output);
bool process_if(token *input_token,  FILE* input, FILE* output);
bool process_while(token *input_token,  FILE* input, FILE* output);
bool function_define(token *input_token, FILE* input, FILE* output);
bool function_call(token *input, FILE* output);

bool compile(FILE *input, FILE *output);

#endif