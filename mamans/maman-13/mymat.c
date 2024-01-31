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
    char temp_mat[10];
    int res;

    res = scanf("%5s%*[^,\n] ", temp_mat);
    // if (res = 0){
    //     return NULL;
    // }
    
    printf("%s ", temp_mat);
    return sort_mat(temp_mat, matrices);
}

void
read_to_delim(char delim){
    while(getchar() != delim){;}
}


void
read_to_end_of_line(void){
    while(getchar() != '\n'){;}
}

void 
read_mat(const MATRICES matrices) {
    mat *mat;
    int i, j; 
    float val;
    char mid_char;
    printf("Reading to ");

    mat = scan_mat(matrices);

    printf("\n");

    if (!mat) {
        report_errors(UNDEFINED_MAT_E);
        read_to_end_of_line();
        return;
    }
    for (i = 0; i < LEN_OF_MAT; i++) {
        for (j = 0; j < LEN_OF_MAT; j++) {
            if ((scanf("%f", &val))){
                mat->data[i][j] = val;
            }
            else {
                report_errors(EXTRA_TEXT_AFTER_COMMAND_E);
                read_to_end_of_line();
                return;
            }
            if (scanf("%c", &mid_char)){
                if (mid_char == '\n') {
                    return;
                }
                else if (mid_char == ',') { 
                    continue;
                }
                else { 
                    report_errors(ARGUMENT_NOT_NUMBER_E);
                    return;
                report_errors(ARGUMENT_NOT_NUMBER_E);
                return;}
            }
            else {
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

    printf("Printing ");

    mat = scan_mat(matrices);

    printf("\n");

    if (!mat) {
        report_errors(UNDEFINED_MAT_E);
        read_to_end_of_line();
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

    printf("Adding ");
    mat_a = scan_mat(matrices);
    printf("and ");
    mat_b = scan_mat(matrices);
    printf("to ");
    mat_c = scan_mat(matrices);
    printf("\n");

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
    printf("Substracting ");
    mat_a = scan_mat(matrices);
    printf("by ");
    mat_b = scan_mat(matrices);
    printf("to ");
    mat_c = scan_mat(matrices);
    printf("\n");

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
    printf("Multipling ");
    mat_a = scan_mat(matrices);
    printf("by ");
    mat_b = scan_mat(matrices);
    printf("to ");
    mat_c = scan_mat(matrices);
    printf("\n");

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
    printf("Multipling ");
    mat_a = scan_mat(matrices);
    printf("by ");
    scanf("%lf%*[, \t]", &scalar);
    printf("to ");
    mat_b = scan_mat(matrices);
    printf("\n");

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

    printf("Transposing ");
    mat_a = scan_mat(matrices);
    printf("to ");
    mat_b = scan_mat(matrices);
    printf("\n");

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
    printf("Wellcome to the matrices calculator program\n");
    printf("Ready for command:\n");

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
            printf("Stopping the program.\n");
            return 0;
        }
        else {
            report_errors(UNDEFINED_COMMAND_E);
            read_to_end_of_line();
        }

        printf("Ready for the next command:\n");
    }
    printf("Error: EOF has entered ");

    return 0;
}
