#include "mymat.h"

int main(void) {
    mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;
    MATRICES my_mats;
    my_mats.MAT_A = &MAT_A;
    my_mats.MAT_B = &MAT_B;
    my_mats.MAT_C = &MAT_C;
    my_mats.MAT_D = &MAT_D;
    my_mats.MAT_E = &MAT_E;
    my_mats.MAT_F = &MAT_F;

    init_mats(my_mats);
    mymat(my_mats);

    return 0;
}
