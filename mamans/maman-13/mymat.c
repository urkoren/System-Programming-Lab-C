#include "mymat.h"

void 
reset_mat(mat *mat) {
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

mat
*scan_mat(const MATRICES matrices)
{
    mat *mat;
    char temp_mat[10];

    scanf("%5s%*[,] ", temp_mat);
    return sort_mat(temp_mat, matrices);
}

void 
read_mat(const MATRICES matrices) {
    /* TODO: Exceed values to include - not more then mats fields */
    mat *mat;
    int i, j; 
    float val;

    mat = scan_mat(matrices);

    if (!mat) {
        report_errors(UNDEFINED_MAT_E);
        return;
    }
    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            if ((scanf("%f%*[, \t]", &val))){
                mat->data[i][j] = val;
            }
            else {
                report_errors(ARGUMENT_NOT_NUMBER_E);
                return;
            }
        }
    }
    while(getchar() != '\n'){;}
}

void 
print_mat(const MATRICES matrices) {
    mat *mat;
    int i, j;

    mat = scan_mat(matrices);

    if (!mat) {
        report_errors(UNDEFINED_MAT_E);
        return;
    }
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

void 
add_mat(const MATRICES matrices)
{
    mat *mat_a, *mat_b, *mat_c;
    int i, j;
    mat_a = scan_mat(matrices);
    mat_b = scan_mat(matrices);
    mat_c = scan_mat(matrices);

    if (!mat_a && !mat_b && !mat_c) {
        return;
    }

    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            mat_c->data[i][j] = mat_a->data[i][j] + mat_b->data[i][j];
        }
    }
}

void 
sub_mat(const MATRICES matrices)
{
    mat *mat_a, *mat_b, *mat_c;
    int i, j;
    mat_a = scan_mat(matrices);
    mat_b = scan_mat(matrices);
    mat_c = scan_mat(matrices);

    if (!mat_a && !mat_b && !mat_c) {
        return;
    }

    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            mat_c->data[i][j] = mat_a->data[i][j] - mat_b->data[i][j];
        }
    }
}

void
mul_mat(const MATRICES matrices)
{
    mat *mat_a, *mat_b, *mat_c;
    int i, j, k;
    mat_a = scan_mat(matrices);
    mat_b = scan_mat(matrices);
    mat_c = scan_mat(matrices);

    if (!mat_a && !mat_b && !mat_c) {
        return;
    }

    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            for(k = 0; k < LEN_OF_MAT; k++) {
                mat_c->data[i][j] = mat_a->data[i][k] * mat_b->data[k][j];
            }
        }
    }
}

void
mul_scalar(const MATRICES matrices)
{
    mat *mat_a, *mat_b;
    int i, j;
    double scalar;
    mat_a = scan_mat(matrices);
    scanf("%lf%*[, \t]", &scalar);
    mat_b = scan_mat(matrices);

    if (!mat_a || !mat_b) {
        return;
    }

    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            mat_b->data[i][j] = mat_a->data[i][j] * scalar;
        }
    }
}

void
trans_mat(const MATRICES matrices)
{
    mat *mat_a, *mat_b;
    int i, j;
    mat_a = scan_mat(matrices);
    mat_b = scan_mat(matrices);

    if (!mat_a && !mat_b) {
        return;
    }

    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            mat_b->data[i][j] = mat_a->data[i][j];
        }
    }
}


mat
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
        return NULL;
    }
}

int 
mymat(MATRICES mats) {
    char command[20];

    while (get_word(command) != EOF) {
        if (strcmp(command, "read_mat") == 0) {
            read_mat(mats);
        }
        else if (strcmp(command, "print_mat") == 0) {
            print_mat(mats);
        }
        else if (strcmp(command, "add_mat") == 0) {
            add_mat(mats);
        }
        else if (strcmp(command, "sub_mat") == 0) {
            sub_mat(mats);
        }
        else if (strcmp(command, "mul_mat") == 0) {
            mul_mat(mats);
        }
        else if (strcmp(command, "mul_scalar") == 0) {
            mul_scalar(mats);
        }
        else if (strcmp(command, "trans_mat") == 0) {
            trans_mat(mats);
        }
        else if (strcmp(command, "stop") == 0) {
            return 0;
        }
        else {
            report_errors(UNDEFINED_COMMAND_E);
        }
    }
    return 0;
}
