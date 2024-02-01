#ifndef IO_H_
#define IO_H_

#include "common.h"

#define get_word(buf) scanf("%s", (buf))

typedef enum {
    UNDEFINED_MAT_E             = 0x01,
    UNDEFINED_COMMAND_E         = 0x02,
    ARGUMENT_NOT_NUMBER_E       = 0x04,
    EXTRA_TEXT_E                = 0x08,
    MISS_ARG_E                  = 0x10,
    ILLEGAL_COMA_E              = 0x20,
    MISS_COMMA_E                = 0x40,
    MULT_COMMA_E                = 0x80,
    ARG_NOT_SCALAR              = 0x100,
    EXTRA_TEXT_AFTER_COMMAND_E  = 0x200
} error_t;

/* Returns 1 if error exist in flags, else return 0 */
extern int
has_error(unsigned int flags, error_t error);

/* Reports all errors in flags */
extern void
report_errors(unsigned int flags);

#endif /* IO_H_ */
