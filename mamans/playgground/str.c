#include "str.h"

/* Struct Declarations */

struct string_s {
    char    *buf;
    size_t  len;
    size_t  capacity;
};

typedef struct string_array_s {
    string  *strings;
    size_t  len;
    size_t  capacity;
};

/* Defines */
#define next_bufsize(curr) (\
    (curr) > 0 \
    ? ( (curr) + ((size_t)((curr) * increase_mult)) )\
    : ( bufsize_start )\
)

#define str_alloc(str)\
do {\
    size_t s = next_bufsize(str.capacity);\
    str.buf = (char*) realloc(str.buf, s);\
    if (!str.buf) {\
        fprintf(\
            stderr, \
            "OUT OF MEMORY! BUY MORE RAM KEKW");\
        str_free(str);\
        return str;\
    }\
} while(0)

#define str_free(str)\
do {\
    free(str.buf);\
    str.buf = NULL;\
    str.len = 0;\
    str.capacity = 0;\
} while (0)

#define str_append(to_str, from_str)
do {\
    int total = to_str.len + from_str.len;\
    if (to_str.capacity < total) 
} while(0)


/* Constant Declarations */
const size_t bufsize_start = 128;
const size_t increase_mult = 1.6;

/* Method Definitions */

string new_str(Optional char* c_str)
{
    string str;
    size_t s = 0;

    if (c_str != NULL) s = strlen(c_str);
    str.len = s;
    str.capacity = s;
    str_alloc(str);
    if (s) memcpy(str.buf, c_str, s);
    return str;
}
