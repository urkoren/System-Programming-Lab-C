#include "io.h"
#include "analyze.h"


int
has_error(unsigned int flags, Error error)
{
    return flags & error;
}

void
report_errors(unsigned int flags)
{
    if (!flags) {
        return;
    }
    if (has_error(flags, UNDEFINED_MAT_E)) {
        printf("Error : Undefined matrix name\n");
    }
    else if (has_error(flags, UNDEFINED_COMMAND_E)) {
        printf("Error : Undefined command name\n");
    }
    else if (has_error(flags, ARGUMENT_NOT_NUMBER_E)) {
        printf("Error : Argument is not a real number\n");
    }
    else if (has_error(flags, EXTRA_TEXT_E)) {
        printf("Error : Extaneous text after end of command\n");
    }
    else if (has_error(flags, MISSING_ARG_E)) {
        printf("Error : Missing argument\n");
    }
    else if (has_error(flags, ILLEGAL_COMMA_E)) {
        printf("Error : Illegal comma\n");
    }
    else if (has_error(flags, MISSING_COMMMA_E)) {
        printf("Error : Missing comma\n");
    }
    else if (has_error(flags, MULT_COMMA_E)) {
        printf("Error : Multiple consecutive commas\n");
    }
    else if (has_error(flags, ARG_NOT_SCALAR)) {
        printf("Error : Argument is not a scalar\n");
    }
    else if (has_error(flags, EXTRA_TEXT_AFTER_COMMAND_E)) {
        printf("Error : Extranous text after end of command\n");
    }
    else if (has_error(flags, ILLEGAL_CHAR_E)) {
        printf("Error : Illegal name\n");
    }
}

void print_line(char* line) {
    int i = 0;

    if (!line) {
        return;
    }

    for (i = 0; i < LINE_SIZE; i ++) {
        if (line[i] == '\0') {
            break;
        }
        putchar(line[i]);
    }
    putchar('\n');
}

int get_line(char* line, Error* error) {
    int i = 0;
    char x;

    clean_line(line);
    while ((x = getchar()) != '\r' && x != '\n') {
        if ((i == 0 || line[i-1] == ' ') && (x == ' ' || x == '\t')) {
            /* multiple white chars */
            continue;
        } else if  (x == EOF) {
            return -1;/* EOF */
        } else if (x == '\r') {
            break;
        } else if (i == LINE_SIZE) {/* line length error */
            while ((x = getchar()) != '\n') {/* unusable data */
                if  (x == EOF) {
                    return -1;/* EOF */
                } else if (x != ' ' && x != '\t') {/* if a non-white char */
                    *error = EXTRA_TEXT_AFTER_COMMAND_E; /* fix */
                }
            }
            break;
        }
        if (x == '\t') {
            x = ' ';
        }
        line[i] = x;
        i += 1;
    }
    return 0;
}

void clean_line(char* line) {
    int i = 0;
    for (i = 0; i < LINE_SIZE; i ++) {
        line[i] = '\0';
    }
}

Command get_command(char* line, int* iterator) {
    Command command = ERROR;
    char* read_mat = "read_mat";
    char* print_mat ="print_mat";
    char* add_mat = "add_mat";
    char* sub_mat = "sub_mat";
    char* mul_mat = "mul_mat";
    char* mul_scalar = "mul_scalar";
    char* trans_mat = "trans_mat";
    char* stop = "stop";
    
    while (line[*iterator] == ' ' || line[*iterator] == '\t') {
        *iterator += 1;
    }
    if (line[*iterator] == '\0' || line[*iterator] == '\r') {
        command = EMPTY_LINE;
    } else if (check(&line[*iterator], read_mat, strlen(read_mat))) {
        *iterator += strlen(read_mat);
        command = READ;
    } else if (check(&line[*iterator], print_mat, strlen(print_mat))) {
        *iterator += strlen(print_mat);
        command = PRINT;
    } else if (check(&line[*iterator], add_mat, strlen(add_mat))) {
        *iterator += strlen(add_mat);
        command = ADD;
    } else if (check(&line[*iterator], sub_mat, strlen(sub_mat))) {
        *iterator += strlen(sub_mat);
        command = SUB;
    } else if (check(&line[*iterator], mul_mat, strlen(mul_mat))) {
        *iterator += strlen(mul_mat);
        command = MUL_MAT;
    } else if (check(&line[*iterator], mul_scalar, strlen(mul_scalar))) {
        *iterator += strlen(mul_scalar);
        command = MUL_SCALAR;
    } else if (check(&line[*iterator], trans_mat, strlen(trans_mat))) {
        *iterator += strlen(trans_mat);
        command = TRANS;
    } else if (check(&line[*iterator], stop, strlen(stop))) {
        *iterator += strlen(stop);
        command = STOP;
    }

    return command;
}

Error get_members(char* line, int iterator, double members[]) {
    int i = 0;
    int comma = 0;/* chacks for a comma */
    char* ptr;
    double num;
    for (i = 0; i < MAT_SIZE*MAT_SIZE; i++) {
        members[i] = 0;/* reset */
    }

    i = 0;
    while ((iterator < LINE_SIZE) && (line[iterator] != '\0')) {
        if (line[iterator] == ' ' || line[iterator] == '\t') {
            iterator++;
        } else if (line[iterator] == ',') {
            if (!comma) {/* the comma after the mat name */
                comma = 1;
                iterator++;
            } else {/* multiple consecutive commas */
                return MULT_COMMA_E;
            }
        } else if (isdigit(line[iterator]) || (line[iterator] == '-' && isdigit(line[iterator+1]))) {/* if char is a digit or a sign */
            if (!comma) {/* missing a comma after the mat name */
                return MISSING_COMMMA_E;
            }
            num = strtod(&line[iterator], &ptr);
            while ((&line[iterator]) != ptr) {
                iterator++;
            }
            comma = 0;
            if (i < MAT_SIZE*MAT_SIZE) {
                members[i++] = num;
            }
        } else {
            return ARGUMENT_NOT_NUMBER_E;
        }
    }/* while */
    if (comma) {
        return ILLEGAL_COMMA_E;
    } else if (!i) {
        return MISSING_ARG_E;
    }
    return NONE;
}

int check(char* first, char* second, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        if (first[i] != second[i]) {
            return 0;
        }
    }
    return 1;
}
