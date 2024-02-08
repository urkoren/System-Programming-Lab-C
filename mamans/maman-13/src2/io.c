#include "io.h"


int 
skip_to_token(FILE *f, char token, bool_t ignore_eol)
{
    char c;
    assert(f);
    for (c = fgetc(f); !is_eol_or_tok(c, token); c = fgetc(f)) {}
    return (feof(f) ? EOF: ungetc(c, f));
}

int
skip_spaces(FILE *f)
{
    return 0;
}

int
get_word(FILE *f, char *buf, size_t maxlen)
{
    return 0;
}

int
get_line(FILE *f, char *dst, size_t maxlen)
{
    return 0;
}


