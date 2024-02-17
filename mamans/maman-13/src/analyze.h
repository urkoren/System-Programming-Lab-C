#ifndef __ANALYZE__H__
#define __ANALYZE__H__

#include "io.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define MAT_SIZE 4
#define LINE_SIZE 80

typedef enum command_t {
    READ,
    PRINT,
    ADD,
    SUB,
    MUL_MAT,
    MUL_SCALAR,
    TRANS,
    STOP,
    ERROR,
    EMPTY_LINE
} Command;


typedef enum mat_name_t {
    MATA = 0,
    MATB = 1,
    MATC = 2,
    MATD = 3,
    MATE = 4,
    MATF = 5,
    ILLEGAL_NAME = 6,
    EMPTY = 7
} MatName;

typedef struct {
    double data[MAT_SIZE][MAT_SIZE];
} mat;

typedef struct {
    mat *MAT_A;
    mat *MAT_B;
    mat *MAT_C;
    mat *MAT_D;
    mat *MAT_E;
    mat *MAT_F;
} MATRICES;

typedef struct {
    mat x;
    mat y;
    mat z;
} MAT_ARGS;






/**
 * List of functions in this header:
 *
 *	analyze - analyze the line.
 *
 *	get_command - returns the command in the line.
 *	get_name - returns the name of the mat.
 *	get_members - returns an array with the mat's parameters.
 *
 *	check - checks if the strings are the same.
 *
 */


/**
 * @brief: Analyze the line.
 *          1. Sends the line to get_command func:
 *              If command is EMPTY_LINE then returns.
 *              Else if it's ERROR then sets error to INVALID_COMMAND and returns.
 *              Else if the char right after the command isn't a 'white char':
 *               if char is a comma then sets error to ILLEGAL_COMMA.
 *               else if command is STOP and char marks end of line then returns.
 *               else sets error to INVALID_COMMAND and returns.
 *          2. If command isn't STOP, sends line to get_name func to get the mat's name:
 *              If returned ILLEGAL_NAME, then sets error to INVALID_MAT.
 *          3. If command isn't PRINT:
 *              If command is READ, goes to get_members func and returns.
 *              Else, tries to get the second and third mats' names. Incase of
 *               an error (such as: INVALID_MAT, MULTIPLE_COMMAS, MISS_ARG_E
 *               or ILLEGAL_CHAR) returns after setting error to the problem.
 *          4. Checks the rest of the line to see if there is an error (such as:
 *               ILLEGAL_COMMA or ILLEGAL_ENDING).
 *              
 * 
 * @param line - array of chars, the size of LINE_SIZE (80). doesn't change it.
 * @param command - pointer to store in it the command.
 * @param x - pointer to store in it the first mat's name, if there is one.
 * @param y - pointer to store in it the second mat's name, if there is one.
 * @param z - pointer to store in it the third mat's name, if there is one.
 * @param members - array to store in it the mat's parameters, if command is read.
 *                  members is the size of MAT_SIZE (16).
 * @param scalar - pointer to store the scalar for mul_scalar.
 * @param error - pointer to store in it the error in the line, if there is one.
 */
void analyze(char* line, Command* command, MAT_ARGS args,
                double* members, double* scalar, Error* error, MATRICES matrices); 

/**
 * @brief: Analyzes the command inside the line and returns it.
 *         As long as line[*iterator] is a 'white char' advances the iterator.
 *         After that, compares the text in the line to the commands:
 *              If recognizes a command, advances the iterator to right after
 *               the command and returns the command.
 *              Else, returns ERROR.
 *
 *         NOTE: doesn't check if there is an illegal comma or char right after
 *                the command.
 * 
 * @param line - array of chars, the size of LINE_SIZE (80). doesn't change it.
 * @param iterator - pointer to int that holds the current place in the line.
 *
 * @return: ERROR - if doesn't recognize the command (error = INVALID_COMMAND).
 *          EMPTY_LINE - if line is empty.
 *          READ
 *          PRINT
 *          ADD
 *          SUB
 *          MUL_MAT
 *          MUL_SCALAR
 *          TRANS
 *          STOP
 */
Command get_command(char* line, int* iterator);

/**
 * @brief: Analyzes the mat's name inside the line and returns it.
 *         As long as line[*iterator] is a 'white char' advances the iterator.
 *         After that, compares the text in the line to the mats' names:
 *              If recognizes a name, advances the iterator to right after
 *               the name and returns the name.
 *              Else, returns ERROR.
 *
 *         NOTE: doesn't check if there is an illegal comma or char right after
 *                the name.
 * 
 * @param line - array of chars, the size of LINE_SIZE (80). doesn't change it.
 * @param iterator - pointer to int that holds the current place in the line.
 *
 * @return: ILLEGAL_NAME - if doesn't recognize the mat's name (error = INVALID_MAT).
 *          MATA
 *          MATB
 *          MATC
 *          MATD
 *          MATE
 *          MATF
 */
extern mat
*get_mat(char* line, int* iterator, MATRICES matrices);

Error get_members(char* line, int iterator, double members[]);

/**
 * @brief: Checks if the two strings are the same at the given length.
 * 
 * @param first - first string
 * @param second - second string
 * @param size - size of the strings (or the smaller one of the two).
 *
 * @return: 0, if the strings aren't the same.
 *          1, if are the same.
 */
int check(char* first, char* sec, int size);


#endif /* __ANALYZE__H__ */
