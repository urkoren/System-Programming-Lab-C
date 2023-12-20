#ifndef DETAB_H_
#define DETAB_H_

#include <stdio.h>

#define LINE_BUFSIZE 100
 
extern void detab(char line[LINE_BUFSIZE], int n_spaces);

#endif /* DETAB_H_ */
