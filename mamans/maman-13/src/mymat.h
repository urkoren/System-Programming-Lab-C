#ifndef __SET__H__
#define __SET__H__

#include "io.h"
#include "analyze.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>


extern Error 
read_mat(mat x, double nums[]);

extern void
init_mats(MATRICES mats);

extern void
init_mat_args(MAT_ARGS args);

extern mat
*scan_mat(const MATRICES matrices);

extern void 
print_mat(mat x);

extern void 
add_mat(mat x, mat y, mat z);

extern void 
sub_mat(mat x, mat y, mat z);

extern void
mul_mat(mat x, mat y, mat z);

extern void
mul_scalar(mat x, double scalar, mat z);

extern void
trans_mat(mat x, mat z);

extern void 
stop(void);


#endif  /*!__SET__H__*/
