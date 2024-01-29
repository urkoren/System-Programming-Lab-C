#include <stdio.h>
#include <string.h>
#include "io.h"

#define LEN_OF_MAT 4

typedef struct {
    float data[LEN_OF_MAT][LEN_OF_MAT];
} mat;

typedef struct {
    mat *MAT_A;
    mat *MAT_B;
    mat *MAT_C;
    mat *MAT_D;
    mat *MAT_E;
    mat *MAT_F;
}MATRICES;

extern void 
reset_mat(mat *mat);
extern void
init_mats(MATRICES mats);
mat
*scan_mat(const MATRICES matrices);
extern void 
read_mat(const MATRICES matrices);
extern void 
print_mat(const MATRICES matrices);
extern void 
add_mat(const MATRICES matrices);
extern void 
sub_mat(const MATRICES matrices);
extern void
mul_mat(const MATRICES matrices);
extern void
mul_scalar(const MATRICES matrices);
extern void
trans_mat(const MATRICES matrices);
extern mat
*sort_mat(const char *mat_name, MATRICES matrices);
extern int 
mymat(MATRICES mats);
