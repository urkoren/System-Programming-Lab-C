#include "io.h"

int
has_error(unsigned int flags, error_t error)
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
        printf("Undefined matrix name\n");
    }
    if (has_error(flags, UNDEFINED_COMMAND_E)) {
        printf("Undefined command name\n");
    }
    if (has_error(flags, ARGUMENT_NOT_NUMBER_E)) {
        printf("Argument is not a real number\n");
    }
    if (has_error(flags, EXTRA_TEXT_E)) {
        printf("Extaneous text after end of command\n");
    }
    if (has_error(flags, MISS_ARG_E)) {
        printf("Missing argument\n");
    }
    if (has_error(flags, ILLEGAL_COMA_E)) {
        printf("Illegal comma\n");
    }
    if (has_error(flags, MISS_COMMA_E)) {
        printf("Missing comma\n");
    }
    if (has_error(flags, MULT_COMMA_E)) {
        printf("Multiple consecutive commas\n");
    }
    if (has_error(flags, ARG_NOT_SCALAR)) {
        printf("Argument is not a scalar\n");
    }
    if (has_error(flags, EXTRA_TEXT_AFTER_COMMAND_E)) {
        printf("Extranous text after end of command\n");
    }
}