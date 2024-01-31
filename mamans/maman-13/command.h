#ifndef COMMAND_H_
#define COMMAND_H_

#include <stdio.h>

typedef char byte;

typedef enum 
boolean_enum {
    FALSE   = 0,
    TRUE    = 1
} boolean;

typedef enum 
instruction_enum {
    ADD,
    STOP,
    READ,
    PRINT,
    TRANSPOSE,
    SUBSTRACT,
    MULTIPLY_MAT,
    MULTIPLY_SCALAR
} instruction_t; 

typedef struct 
command_args_s {
    size_t  nof_args;
    size_t  min_nof_args;
    size_t  max_nof_args;
    size_t  seperator;
    boolean skip_whitespace;
    char    *seperator_scanf_fmt;
    char    *arg_scanf_fmt;
    char    *arg_seperator;
    char    **args;
} command_args_t;

typedef struct 
command_s {
    command_args_t  arguments;
    instruction_t   instruction;
} command_t;

extern int 
parse_instruction(FILE *from, command_t *to_cmd);

extern int
parse_argument(FILE *from, command_t *to_cmd);

void
call_instruction(command_t *cmd)
{
    switch (cmd->instruction) {
        case READ:
            mat_read(cmd);
            break;
        case PRINT:
            mat_print(cmd);
            break;
        case MULTIPLY:
            mat_multiply(cmd);
            break;
        case SUBSTRACT:
            mat_substract(cmd);
            break;
    }
}


#endif /* COMMAND_H_ */
