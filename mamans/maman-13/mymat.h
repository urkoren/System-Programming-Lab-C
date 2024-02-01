#ifndef MYMAT_H_
#define MYMAT_H_

#include "common.h"
#include "io.h"

#define LEN_OF_MAT 4

typedef struct {
    float data[LEN_OF_MAT][LEN_OF_MAT];
} mat;

typedef struct {
    mat matrix;
    char *identifier;
} mat_info;

typedef struct {
    mat_info MAT_A;
    mat_info MAT_B;
    mat_info MAT_C;
    mat_info MAT_D;
    mat_info MAT_E;
    mat_info MAT_F;
} MATRICES;


/* char* get_mat_name() */

/* Function: reset_mat */
/* Description-TBD. */
extern void 
reset_mat(mat *mat);

/* Function: init_mats */
/*  */
/* Description-TBD. */

extern void
init_mats(MATRICES mats);

/* Function: scan_mat */
/*  */
/* Description-TBD. */

extern mat*
scan_mat(const MATRICES matrices);

/* Function: read_mat */
/*  */
/* Description-TBD. */

extern void 
read_mat(const MATRICES matrices);

/* Function: print_mat */
/*  */
/* Description-TBD. */

extern void 
print_mat(const MATRICES matrices);

/* Function: add_mat */
/*  */
/* Description-TBD. */

extern void 
add_mat(const MATRICES matrices);

/* Function: sub_mat */
/*  */
/* Description-TBD. */

extern void 
sub_mat(const MATRICES matrices);

/* Function: mul_mat */
/*  */
/* Description-TBD. */

extern void
mul_mat(const MATRICES matrices);

/* Function: mul_scalar

Description-TBD.  */

extern void
mul_scalar(const MATRICES matrices);

/* Function: trans_mat

Description-TBD.  */

extern void
trans_mat(const MATRICES matrices);

/* Function: *sort_mat

Description-TBD.  */

extern mat
*sort_mat(const char *mat_name, MATRICES matrices);

/* Function: mymat

Description-TBD.  */

extern int 
mymat(MATRICES mats);

#endif /* MYMAT_H_ */
