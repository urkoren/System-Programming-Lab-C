#include "io.h"


int
is_in_tok_buf(const char c, const char *tok_buf)
{
    int i = 0;

    IO_BUF_ASSERT( tok_buf )
    
    while ( tok_buf[i] ) {
        if ( is_tok(c, tok_buf[i]) )
            return 1;
        i++;
    }
    return 0;
}

int 
fskip_to_any(FILE *f, const char *tokens, bool_t ignore_eol)
{
}

int 
fskip_to_token(FILE *f, char tok, bool_t ignore_eol)
{
    char c = 0;
    int done = 0;

    IO_F_ASSERT(f)

    while (!done) {
        c = fgetc(f);
        done = (
            feof(f) 
            || ( ignore_eol && is_tok(c, tok) ) 
            || is_eol_or_tok(c, tok) 
        );
    }
    
    return ( is_tok(c, tok) ? ungetc(c, f) : EOF );
}

int
fskip_whitespace(FILE *f)
{
    char c;
    IO_F_ASSERT(f)
    while ( !feof(f) && !isgraph(c = fgetc(f)) ) {}
    return ( isgraph(c) ? ungetc(c, f) : EOF );
}

int
fskip_graphic(FILE *f)
{
    char c;
    IO_F_ASSERT(f)
    while ( !feof(f) && isgraph(c = fgetc(f)) ) {}
    return ( (!isgraph(c)) ? ungetc(c, f) : EOF );
}

int
fget_word(FILE *f, char *buf, size_t maxlen)
{
    char c = 0;
    size_t i = 0;
    
    IO_F_ASSERT(f)
    IO_BUF_ASSERT(buf)

    if ( !isgraph(c = fgetc(f)) && !feof(f) )
        fskip_whitespace(f); 

    while ( isgraph(c = fgetc(f)) && i < (maxlen - 1) )
        buf[i++] = c;

    buf[i] = 0;

    return ( feof(f) ? EOF : ungetc(c, f) );
}

int
fget_line(FILE *f, char *dst, size_t maxlen)
{
    return 0;
}


