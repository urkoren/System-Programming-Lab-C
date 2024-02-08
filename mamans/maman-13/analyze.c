#include "analyze.h"
#include "messages.h"
#include "mymat.h"
#include "io.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void 
analyze(
    char* line, 
    Command* command, 
    mat *x, 
    mat *y, 
    mat *z,
    double* members, 
    double* scalar, 
    Error* error, 
    MATRICES matrices
) 
{
    int i = 0, comma = 0;
    char* ptr;
    *error = NONE;/* resets it for later use. */


    *command = get_command(line, &i);
    if (*command == EMPTY_LINE) {
        return;
    } else if (*command == ERROR) {
        *error = UNDEFINED_COMMAND_E;
        return;
    } else if (line[i] != ' ' && line[i] != '\t') {
        if (line[i] == ',') {
            *error = ILLEGAL_COMMA_E;
        } else if (line[i] == '\0' || line[i] == '\r') {
            if (*command != STOP) {
                *error = MISS_ARG_E;
            }
        } else {
            *error = ILLEGAL_CHAR_E;
        }
        return;
    }
    /* command is OK and has a white char after it */
    if (*command != STOP) {
        /* printf("line: %s, i: %d, matrices: \n", line, i); */
        /* print_mat(matrices.MAT_A); */
        /* print_mat(matrices.MAT_B); */
        /* print_mat(matrices.MAT_C); */
        /* print_mat(matrices.MAT_D); */
        /* print_mat(matrices.MAT_E); */
        /* print_mat(matrices.MAT_F); */
        x = get_mat(line, &i, matrices);
        if (!(x)) {
            *error = MISS_ARG_E;
            return;
        }
        if (*command != PRINT) {/* needs a comma now */
            if (*command == MUL_SCALAR) {
                comma = 0;
                while (line[i]) {
                    if (line[i] == ',') {
                        if (!comma) {
                            comma = 1;
                            i++;
                        } else {
                            *error = MULT_COMMA_E;
                        }
                    } else if (line[i] == ' ' || line[i] == '\t') {
                        i++;
                    } else {
                        if (comma) {
                            if (isdigit(line[i]) || (line[i] == '-' && isdigit(line[i+1]))) {
                                break;
                            }
                            *error = ARGUMENT_NOT_NUMBER_E;
                        } else {
                            *error = MISSING_COMMMA_E ;
                        }
                        return;
                    }
                }
                *scalar = strtod(&line[i], &ptr);
                while (&line[i] != ptr) {
                    i++;
                }
            }
            if (*command == READ) {
                *error = get_members(line, i, members);
                return;
            } else {/* add/sub/mul_mat/mul_scalar/trans*/
                comma = 0;
                while (y == NULL) {
                    if ((line[i] == ' ') || (line[i] == '\t')) {
                        i++;
                    } else if (line[i] == ',') {
                        if (!comma) {
                            comma = 1;
                            i++;
                        } else {
                            *error = MULT_COMMA_E;
                            return;
                        }
                    } else if (line[i] == '\0' || line[i] == '\r') {/* cutting line short */
                        *error = MISS_ARG_E;
                        return;
                    } else {
                        if (comma) {
                            y = get_mat(line, &i, matrices);
                            if (y == NULL) {
                                *error = MISS_ARG_E;
                                return;
                            }
                        } else {/* illegal char */
                            *error = MISSING_COMMMA_E;
                            return;
                        }
                    }
                }
                if (*command != MUL_SCALAR && *command != TRANS) {
                    comma = 0;
                    while (z == NULL) {
                        if ((line[i] == ' ') || (line[i] == '\t')) {
                            i += 1;
                        } else if (line[i] == ',') {
                            if (!comma) {
                                comma = 1;
                                i++;
                            } else {
                                *error = MULT_COMMA_E;
                                return;
                            }
                        } else if (line[i] == '\0' || line[i] == '\r') {/* cutting line short */
                            *error = MISS_ARG_E;
                            return;
                        } else {
                            if (comma) {
                            z = get_mat(line, &i, matrices);
                            if (z == NULL) {
                                *error = MISS_ARG_E;
                                return;
                            }
                        } else {/* illegal char */
                            *error = MISSING_COMMMA_E;
                            return;
                        }
                        }
                    }/* while */
                }/* command = add/sub/mul_mat */
            }/* command = add/sub/mul_mat/mul_scalar/trans */
        }/* command != print */
    }/* command != stop */

    /* all commands but read */
    while (i < LINE_SIZE) {
        if (line[i] == '\0' || line[i] == '\r') {
            return;
        } else if (line[i] == ' ' || line[i] == '\t') {
            i += 1;
        } else {
            *error = EXTRA_TEXT_E;
            return;
        }
    }/* while */
}

mat *get_mat(char* line, int* iterator, MATRICES matrices) {
    char* mat_a = "MAT_A";
    char* mat_b = "MAT_B";
    char* mat_c = "MAT_C";
    char* mat_d = "MAT_D";
    char* mat_e = "MAT_E";
    char* mat_f = "MAT_F";
    int i = *iterator;

    while (i < LINE_SIZE) {
        if (line[i] == ' ' || line[i] == '\t') {
            i += 1;
            continue;
        } else if (line[i] == '\0' || line[i] == '\r') {
            return NULL;
        } else if (strcmp(&line[i], mat_a) == 0) {
            *iterator = i + strlen(mat_a);
            return matrices.MAT_A;
        } else if (strcmp(&line[i], mat_b) == 0) {
            *iterator = i + strlen(mat_b);
            return matrices.MAT_B;
        } else if (strcmp(&line[i], mat_c) == 0) {
            *iterator = i + strlen(mat_c);
            return matrices.MAT_C;
        } else if (strcmp(&line[i], mat_d) == 0) {
            *iterator = i + strlen(mat_d);
            return matrices.MAT_D;
        } else if (strcmp(&line[i], mat_e) == 0) {
            *iterator = i + strlen(mat_e);
            return matrices.MAT_E;
        } else if (strcmp(&line[i], mat_f) == 0) {
            *iterator = i + strlen(mat_f);
            return matrices.MAT_F;
        } else {
            break;
        }
    }
    return NULL;
}
