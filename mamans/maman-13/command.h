#ifndef COMMAND_H_
#define COMMAND_H_

#include "analyze.h"
#include "mymat.h"
#include <stdio.h>
#include "io.h"

extern void do_command(
    Command command, 
    mat *x, 
    mat *y, 
    mat *z, 
    MATRICES *mat_array, 
    double scalar, 
    double members[]
);

#endif /* COMMAND_H_ */

