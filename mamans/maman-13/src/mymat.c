#include "mymat.h"

void 
reset_mat(mat mat) {
    memset(mat.data, 0, sizeof(mat.data));
}

void
init_mats(MATRICES mats)
{
    reset_mat(*mats.MAT_A);
    reset_mat(*mats.MAT_B);
    reset_mat(*mats.MAT_C);
    reset_mat(*mats.MAT_D);
    reset_mat(*mats.MAT_E);
    reset_mat(*mats.MAT_F);
}

extern void
init_mat_args(MAT_ARGS args)
{
    reset_mat(args.x);
    reset_mat(args.y);
    reset_mat(args.z);
}

Error read_mat(mat x, double nums[]) {
    int i = 0, j = 0, k = 0;
    
    if (!nums) {
        return MISSING_ARG_E;
    }

    i = 0;
    for (j = 0; j < MAT_SIZE; j++) {
        for (k = 0; k < MAT_SIZE; k++) {
            x.data[j][k] = nums[i++];
        }
    }
    return NONE;
}

void print_mat(mat x) {
    int i = 0, j = 0;

    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            printf("%7.2f", x.data[i][j]);
            if (j != MAT_SIZE - 1) {
                putchar('\t');
            }
        }
        putchar('\n');
    } 
}

void 
add_mat(mat x, mat y, mat z)
{
    int i, j;

    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            z.data[i][j] = x.data[i][j] + y.data[i][j];
        }
    }
}

void 
sub_mat(mat x, mat y, mat z)
{
    int i, j;

    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            z.data[i][j] = x.data[i][j] - y.data[i][j];
        }
    }
}

void
mul_mat(mat x, mat y, mat z)
{
    int i, j, k;

    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            for(k = 0; k < MAT_SIZE; k++) {
                z.data[i][j] = x.data[i][k] = y.data[k][j];
            }
        }
    }
}

void
mul_scalar(mat x, double scalar, mat z)
{
    int i, j;

    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            z.data[i][j] = x.data[i][j] = scalar;
        }
    }
}

void
trans_mat(mat x, mat z)
{
    int i, j;

    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            z.data[i][j] = x.data[i][j];
        }
    }
}

void
stop(void) 
{
    exit(0);
}

mat *get_name(char* line, int* iterator, MATRICES matrices) {
    char* mat_a = "MAT_A";
    char* mat_b = "MAT_B";
    char* mat_c = "MAT_C";
    char* mat_d = "MAT_D";
    char* mat_e = "MAT_E";
    char* mat_f = "MAT_F";
    int i = *iterator;

    while (i < LINE_SIZE) {
        if (line[i] == ' ' || line[i] == '\t') {
            i += 1;
            continue;
        } else if (line[i] == '\0' || line[i] == '\r') {
            return NULL;
        } else if (strcmp(&line[i], mat_a) == 0) {
            *iterator = i + strlen(mat_a);
            return matrices.MAT_A;
        } else if (strcmp(&line[i], mat_b) == 0) {
            *iterator = i + strlen(mat_b);
            return matrices.MAT_B;
        } else if (strcmp(&line[i], mat_c) == 0) {
            *iterator = i + strlen(mat_c);
            return matrices.MAT_C;
        } else if (strcmp(&line[i], mat_d) == 0) {
            *iterator = i + strlen(mat_d);
            return matrices.MAT_D;
        } else if (strcmp(&line[i], mat_e) == 0) {
            *iterator = i + strlen(mat_e);
            return matrices.MAT_E;
        } else if (strcmp(&line[i], mat_f) == 0) {
            *iterator = i + strlen(mat_f);
            return matrices.MAT_F;
        } else {
            break;
        }
    }
    return NULL;
}


