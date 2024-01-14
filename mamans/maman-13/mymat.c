#include <stdio.h>
#include <string.h>

#define LEN_OF_MAT 4

typedef struct {
    float values[LEN_OF_MAT][LEN_OF_MAT];
} MAT;

typedef struct {
    MAT *MAT_A;
}MATRICES;

void reset_mat(MAT *mat) {
    memset(mat->values, 0, sizeof(mat->values));
}

void print_mat(const MATRICES matrices) {
    MAT mat;
    char temp_mat[10];
    scanf("%s", &temp_mat);
    mat = sort_mat(temp_mat, matrices);
    for (int i = 0; i < LEN_OF_MAT; i++) {
        for (int j = 0; j < LEN_OF_MAT; j++) {
            printf("%2.2f\t", mat->values[i][j]);
        }
        printf("\n");
    }
}

MATRICES *sort_mat(const char mat_name, MATRICES matrices) {
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
        // Return NULL or handle the case for an unknown matrix name
        return NULL;
    }
}



int mymat(MATRICES mats) {
    char command[20];

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "print_mat") == 0) {
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
    MATRICES *my_mats;
    my_mats->MAT_A = &MAT_A;

    reset_mat(my_mats->MAT_A);
    mymat(my_mats);

    return 0;
}
