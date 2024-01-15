#include <stdio.h>
#include <string.h>

#define LEN_OF_MAT 4
#define PPRINT_MAT(MAT) pprint_mat(#MAT, (MAT))

typedef struct {
    float data[LEN_OF_MAT][LEN_OF_MAT];
} MAT;

typedef struct {
    MAT *MAT_A;
    MAT *MAT_B;
    MAT *MAT_C;
    MAT *MAT_D;
    MAT *MAT_E;
    MAT *MAT_F;
}MATRICES;

extern int 
mymat(MATRICES mats);
extern MAT 
*sort_mat(const char *mat_name, MATRICES matrices);
extern void 
reset_mat(MAT *mat);
extern void 
print_mat(const MATRICES matrices);
extern void 
pprint_mat(const char *matrix_name, const MAT matrix_data);
void 
read_mat(const MATRICES matrices);
void
init_mats(MATRICES mats);
