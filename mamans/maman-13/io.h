#ifndef _IO_H_
#define _IO_H_
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#ifdef DEBUG
#define DEBUG_LOG(x, ...) printf(1, 2)
#else
#define DEBUG_LOG(x, ...) 
#endif

#define get_word(buf) scanf("%s", (buf))

typedef enum {
    UNDEFINED_MAT_E             = 0x01,
    UNDEFINED_COMMAND_E         = 0x02,
    ARGUMENT_NOT_NUMBER_E       = 0x04,
    EXTRA_TEXT_E                = 0x08,
    MISS_ARG_E                  = 0x10,
    ILLEGAL_COMMA_E             = 0x20,
    MISSING_COMMMA_E                = 0x40,
    MULT_COMMA_E                = 0x80,
    ARG_NOT_SCALAR              = 0x100,
    EXTRA_TEXT_AFTER_COMMAND_E  = 0x200,
    ILLEGAL_CHAR_E              = 0x400,
    NONE                        = 0,

} Error;

/* Returns 1 if error exist in flags, else return 0 */
extern int
has_error(unsigned int flags, Error error);

/* Reports all errors in flags */
extern void
report_errors(unsigned int flags);

extern void
print_line(char*);

extern int
get_line(char*, Error*);

extern void
clean_line(char*);

extern void
report_errors(Error error);


extern void clean_line(char* line);
#endif /* __IO__H__ */
