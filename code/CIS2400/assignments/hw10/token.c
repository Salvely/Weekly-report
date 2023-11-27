#include "token.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int line_number = 0;

bool next_token(FILE *j_file, token *output)
{
    char str[MAX_TOKEN_LENGTH];
    int size = fscanf(j_file, "%s", str);
    if(size <= 0) {
        return true;
    }
    // if it's a comment
    if (!strcmp(str, ";;"))
    {
        strcpy(output->str, str);
        fgets(str, MAX_TOKEN_LENGTH, j_file);
        output->type = COMMENT;
        return true;
    }

    char delim = fgetc(j_file);
    if(delim == '\n') {
        line_number += 1;
    }
    // check each type and store the according info in the struct
    if (strstr(str, "defun"))
    {
        output->type = DEFUN;
    }
    else if (strstr(str, "return"))
    {
        output->type = RETURN;
    }
    else if (strstr(str, "+"))
    {
        output->type = PLUS;
    }
    else if (strstr(str, "-"))
    {
        output->type = MINUS;
    }
    else if (strstr(str, "*"))
    {
        output->type = MUL;
    }
    else if (strstr(str, "/"))
    {
        output->type = DIV;
    }
    else if (strstr(str, "%"))
    {
        output->type = MOD;
    }
    else if (strstr(str, "and"))
    {
        output->type = AND;
    }
    else if (strstr(str, "or"))
    {
        output->type = OR;
    }
    else if (strstr(str, "not"))
    {
        output->type = NOT;
    }
    else if (strstr(str, "lt"))
    {
        output->type = LT;
    }
    else if (strstr(str, "le"))
    {
        output->type = LE;
    }
    else if (strstr(str, "eq"))
    {
        output->type = EQ;
    }
    else if (strstr(str, "ge"))
    {
        output->type = GE;
    }
    else if (strstr(str, "gt"))
    {
        output->type = GT;
    }
    else if (strstr(str, "if"))
    {
        output->type = IF;
    }
    else if (strstr(str, "else"))
    {
        output->type = ELSE;
    }
    else if (strstr(str, "endif"))
    {
        output->type = ENDIF;
    }
    else if (strstr(str, "while"))
    {
        output->type = WHILE;
    }
    else if (strstr(str, "endwhile"))
    {
        output->type = ENDWHILE;
    }
    else if (strstr(str, "drop"))
    {
        output->type = DROP;
    }
    else if (strstr(str, "dup"))
    {
        output->type = DUP;
    }
    else if (strstr(str, "swap"))
    {
        output->type = SWAP;
    }
    else if (strstr(str, "rot"))
    {
        output->type = ROT;
    }
    else if (strstr(str, "arg"))
    {
        output->type = ARG;
        char num[3];
        for (int i = 3; i < 5; i++)
        {
            num[i - 3] = str[i];
        }
        num[2] = '\0';
        output->arg_no = atoi(num);
    }
    // deal with ident
    else if (isalpha(str[0]))
    {
        int i = 1;
        bool is_ident = true;
        while (str[i] != '\0')
        {
            if (!isalnum(str[i]) && (str[i] != '_'))
            {
                is_ident = false;
                break;
            }
            i += 1;
        }
        if (is_ident)
            output->type = IDENT;
    }
    // deal with literal
    else if (!strcmp(str, "0") || atoi(str) != 0)
    {
        output->type = LITERAL;
        output->literal_value = atoi(str);
    }
    // deal with bad token
    else
    {
        output->type = BAD_TOKEN;
        return false;
    }
    strcpy(output->str, str);

    return true;
}

void print_token(FILE *f, token to_print)
{
    fprintf(f, "%s: %d", to_print.str, to_print.type);
    if(to_print.type == LITERAL) {
        fprintf(f, " %x", to_print.literal_value);
    }
    else if(to_print.type == ARG) {
        fprintf(f, " %d", to_print.arg_no);
    }
    fprintf(f, "\n");
}

void write_token(FILE* j_file, FILE* token_out)
{
    token current;
    while(next_token(j_file, &current)) {
        print_token(token_out, current);
    }
}
