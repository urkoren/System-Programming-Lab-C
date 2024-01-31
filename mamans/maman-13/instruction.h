#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <stdio.h>

#define NUM_INSTRUCTIONS 8

#define GENERATE(X, SEP)\
    X(ADD)SEP\
    X(STOP)SEP\
    X(READ)SEP\
    X(PRINT)SEP\
    X(TRANSPOSE)SEP\
    X(SUBSTRACT)SEP\
    X(MULTIPLY_MAT)SEP\
    X(MULTIPLY_SCALAR)


#define END_STATEMENT_TOK ;
#define NEXT_STATEMENT_TOK ,
#define INSTRUCTION_STR(VAL) const char VAL##_S[] = #VAL
#define INSTRUCTION_TYPE(VAL) VAL##_T
#define INSTRUCTION_FUNC(INSTRUCTION) \
extern void \ 
INSTRUCTION(instruction_t instruction)

GENERATE(INSTRUCTION_STR, END_STATEMENT_TOK);
typedef enum {
    GENERATE(INSTRUCTION_TYPE, NEXT_STATEMENT_TOK)
} instruction_type_enum; 
GENERATE(INSTRUCTION_FUNC, END_STATEMENT_TOK);

typedef struct {
    instruction_type_enum   type;
    const char*             str_val;
    size_t                  num_args;
} instruction_t;

typedef const instruction_t instructions_t[NUM_INSTRUCTIONS];
instructions_t instructions = {
    {ADD_T, ADD_S, 3}, 
    {STOP_T, STOP_S, 0}, 
    {READ_T, READ_S, -1},\
    {PRINT_T, PRINT_S, 1},\
    {TRANSPOSE_T, TRANSPOSE_S, 2},\
    {SUBSTRACT_T, SUBSTRACT_S, 3},\
    {MULTIPLY_MAT_T, MULTIPLY_MAT_S, 3},\
    {MULTIPLY_SCALAR_T, MULTIPLY_SCALAR_S, 2}
};

#endif /* INSTRUCTION_H_ */
