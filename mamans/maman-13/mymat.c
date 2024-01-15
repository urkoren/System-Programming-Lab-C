#include "mymat.h"

void 
reset_mat(MAT *mat) {
    memset(mat->data, 0, sizeof(mat->data));
}

void
init_mats(MATRICES mats)
{
    reset_mat(mats.MAT_A);
    reset_mat(mats.MAT_B);
    reset_mat(mats.MAT_C);
    reset_mat(mats.MAT_D);
    reset_mat(mats.MAT_E);
    reset_mat(mats.MAT_F);
}

MAT
*scan_mat(const MATRICES matrices)
{
    MAT *mat;
    char temp_mat[10];

    scanf("%5s%*[,] ", temp_mat);
    mat = sort_mat(temp_mat, matrices);
    if (mat)
        return mat;
}

void 
read_mat(const MATRICES matrices) {
    MAT *mat;
    int i, j; 
    float val;

    mat = scan_mat(matrices);

    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            if ((scanf("%f%*[, \t]", &val))){
                mat->data[i][j] = val;
            }
            else {return;}
        }
    }
}

void 
print_mat(const MATRICES matrices) {
    MAT *mat;
    int i, j;

    mat = scan_mat(matrices);

    if (mat){
        for (i = 0; i < LEN_OF_MAT; i++) {
            printf("[");
            for (j = 0; j < LEN_OF_MAT; j++) {
                printf("%-4.2f", mat->data[i][j]);
                if (j < LEN_OF_MAT-1)
                    printf("\t");
            }
            printf("]\n");
        }
    }
}

void 
add_mat(const MATRICES matrices)
{
    MAT *mat_a, *mat_b, *mat_c;
    int i, j;
    mat_a = scan_mat(matrices);
    mat_b = scan_mat(matrices);
    mat_c = scan_mat(matrices);

    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            mat_c->data[i][j] = mat_a->data[i][j] + mat_b->data[i][j];
        }
    }
}

MAT
*sort_mat(const char *mat_name, MATRICES matrices) {
    if (strcmp(mat_name, "MAT_A") == 0) {
        return matrices.MAT_A;
    } else if (strcmp(mat_name, "MAT_B") == 0) {
        return matrices.MAT_B;
    } else if (strcmp(mat_name, "MAT_C") == 0) {
        return matrices.MAT_C;
    } else if (strcmp(mat_name, "MAT_D") == 0) {
        return matrices.MAT_D;
    } else if (strcmp(mat_name, "MAT_E") == 0) {
        return matrices.MAT_E;
    } else if (strcmp(mat_name, "MAT_F") == 0) {
        return matrices.MAT_F;
    } else {
        printf("Invalid MAT\n");
        return NULL;
    }
}

int 
mymat(MATRICES mats) {
    char command[20];

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "read_mat") == 0) {
            read_mat(mats);
        }
        else if (strcmp(command, "print_mat") == 0) {
            print_mat(mats);
        }
        else if (strcmp(command, "add_mat") == 0) {
            add_mat(mats);
        }
        else if (strcmp(command, "stop") == 0) {
            return 0;
        }
        else {
            printf("Unknown command: %s\n", command);
        }
    }
    return 0;
}

int main(void) {
    MAT MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;
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
