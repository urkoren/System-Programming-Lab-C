#include "mymat.h"

void 
reset_mat(MAT mat) {
    memset(mat.data, 0, sizeof(mat.data));
}

void 
pprint_mat(const char *matrix_name, const MAT matrix_data) 
{
    int i, j;

    fprintf(stdout, "%s = [", matrix_name);
    for (i = 0; i < LEN_OF_MAT; i++) {
        fprintf(stdout, "|\n");
        for (j = 0; j < LEN_OF_MAT; j++) {
            fprintf(stdout, "%*s\n", 4, " ");
            fprintf(stdout, "%.2f", matrix_data.data[i][j]);
        }
        fprintf(stdout, "|\n");
    }
    fprintf(stdout, "]\n");
}

void 
print_mat(const MATRICES matrices) {
    printf("p");
    MAT *mat;
    int i, j;
    char temp_mat[10];

    scanf("%s", temp_mat);

    mat = sort_mat(temp_mat, matrices);

    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            printf("%-2.2f\t", mat->data[i][j]);
        }
        printf("\n");
    }
}

MAT
*sort_mat(const char *mat_name, MATRICES matrices) {
    printf("S");
    if (strcmp(mat_name, "mat_a") == 0) {
        return matrices.MAT_A;
    } else if (strcmp(mat_name, "mat_b") == 0) {
        return matrices.MAT_B;
    } else if (strcmp(mat_name, "mat_c") == 0) {
        return matrices.MAT_C;
    } else if (strcmp(mat_name, "mat_d") == 0) {
        return matrices.MAT_D;
    } else if (strcmp(mat_name, "mat_e") == 0) {
        return matrices.MAT_E;
    } else if (strcmp(mat_name, "mat_f") == 0) {
        return matrices.MAT_F;
    } else {
        return NULL;
    }
}

int mymat(MATRICES mats) {
    char command[20];

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "print_mat") == 0) {
            printf("V");
            print_mat(mats);
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
    MAT MAT_A;
    MATRICES my_mats;
    my_mats.MAT_A = &MAT_A;

    reset_mat(my_mats.MAT_A[0]);
    mymat(my_mats);

    return 0;
}
