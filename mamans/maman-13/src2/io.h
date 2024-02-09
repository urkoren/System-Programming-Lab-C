#ifndef IO_H_
#define IO_H_

/* Includes */

#include "common.h"

/* Defines */

#ifndef IO_F_ASSERT
#   define IO_F_ASSERT(f) if ( (f) == NULL || feof(f) ) { return EOF; }
#endif

#ifndef IO_BUF_ASSERT
#   define IO_BUF_ASSERT(buf) if ( (buf) == NULL ) { return -1; }
#endif

#ifndef is_eol
#   define is_eol(c) ( (int)((c) == '\n' || (c) == EOF) )
#endif 

#ifndef is_tok
#   define is_tok(c, tok) ( (int)((c) == (tok)) )
#endif

#ifndef is_eol_or_tok
#   define is_eol_or_tok(c, tok) ( (int)(is_eol(c) || is_tok((c), (tok))) )
#endif

extern int
is_in_tok_buf(const char c, const char *tok_buf);

/* Skip Methods */

extern int 
fskip_to_any(FILE *f, const char *tokens, bool_t ignore_eol);

extern int 
fskip_to_token(FILE *f, char token, bool_t ignore_eol);

extern int
fskip_whitespace(FILE *f);

extern int
fskip_graphic(FILE *f);


/* Get Methods */

extern int
fget_word(FILE *f, char *dst, size_t maxlen);

extern int
fget_line(FILE *f, char *dst, size_t maxlen);

#endif /* IO_H_ */
