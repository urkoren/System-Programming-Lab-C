#ifndef IO_H_
#define IO_H_

/* Includes */

#include "common.h"

/* Defines */

#ifndef is_eol
#   define is_eol(c) ( (c) == '\n' || (c) == EOF )
#endif 

#ifndef is_tok
#   define is_tok(c, tok) ( (c) == (tok) )
#endif

#ifndef is_eol_or_tok
#   define is_eol_or_tok(c, tok) ( is_eol(c) || is_tok((c), (tok)) )
#endif

/* Skip Methods */

extern int 
skip_to_token(FILE *f, char token, bool_t ignore_eol);

extern int
skip_spaces(FILE *f);

/* Get Methods */

extern int
get_word(FILE *f, char *dst, size_t maxlen);

extern int
get_line(FILE *f, char *dst, size_t maxlen);

#endif /* IO_H_ */
