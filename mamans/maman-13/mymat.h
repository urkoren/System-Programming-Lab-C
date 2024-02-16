<<<<<<< HEAD
#ifndef __SET__H__
#define __SET__H__

=======
#ifndef MYMAT_H_
#define MYMAT_H_

#include "common.h"
#include "io.h"
>>>>>>> 38add6d (refactoring, should not be merged - compiling but not working)
#include "analyze.h"

extern Error 
read_mat(mat *x, double nums[]);

extern void
init_mats(MATRICES mats);

extern mat
*scan_mat(const MATRICES matrices);

extern void 
print_mat(mat *x);

extern void 
add_mat(mat *x, mat *y, mat *z);

extern void 
sub_mat(mat *x, mat *y, mat *z);

extern void
mul_mat(mat *x, mat *y, mat *z);

extern void
mul_scalar(mat *x, double scalar, mat *z);

extern void
trans_mat(mat *x, mat *z);

extern void 
stop(void);


<<<<<<< HEAD
#endif  /*!__SET__H__*/
=======
#endif  /*MYMAT_H_*/
>>>>>>> 38add6d (refactoring, should not be merged - compiling but not working)
