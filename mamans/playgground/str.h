#ifndef STR_H_
#define STR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DefaultVal -1
#define Required
#define Optional
#define AtLeastOne

typedef struct string_s 
string;

typedef struct string_array_s 
string_array;

/* Constructor / Destructor */

extern string
new_str(Optional char *c_str);

extern void
del_str(Required string str);

extern char*
c_str(Required string str);

extern string
slice(
    AtLeastOne int start, 
    AtLeastOne int stop, 
    AtLeastOne int step
);

extern string
slice_start(
    Required int start, 
    Optional int stop
);

extern string
slice_start(
    Required int start, 
    Optional int stop
);

/* String Manipulation Methods */

extern void
append(string dst, string src);

extern void
prepend(string dst, string src);

extern void
strip(string str);

extern void
rstrip(string str);

extern void
lstrip(string str);

extern void
replace(
    string str, 
    string substr_old, 
    string substr_new,
    int max_count
);

extern void
upper(string str);

extern void 
lower(string str);

extern void
removeprefix(string str, string prefix);

extern void
removesuffix(string str, string suffix);


/* String Lookup Methods */

extern int
find(string str);

extern int
rfind(string str);


/* String Array Methods */

extern string_array
split(string str);

extern string_array
rsplit(string str);

extern string_array
lsplit(string str);


/* String Boolean Methods */

extern int
isalnum(string str);

extern int
isspace(string str);

extern int
isdigit(string str);

extern int
isalpha(string str);

extern int
isupper(string str);

extern int
islower(string str);

extern int
contains(string str);

#endif /* STR_H_ */
