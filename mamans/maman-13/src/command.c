#include "command.h"

void do_command(Command command, MAT_ARGS args, MATRICES *mat_array, double scalar, double members[]) {
    mat *x, *y, *z;

    x = &args.x;
    y = &args.y;
    z = &args.z;

    switch (command) {
        case STOP:
            stop();
        case READ:
            if (x == NULL) {
                report_errors(MISSING_ARG_E);
            } else {
                report_errors(read_mat(*x , members));
            }
            return;
        case PRINT:
            if (x == NULL) {
                report_errors(MISSING_ARG_E);
            } else {
                print_mat(*x);
            }
            return;
        case ADD:
            if (x == NULL|| y == NULL || z == NULL) {
                report_errors(MISSING_ARG_E);
            } else {
                add_mat(*x, *y, *z);
            }
            return;
        case SUB:
            if (x == NULL || y == NULL || z == NULL) {
                report_errors(MISSING_ARG_E);
            } else {
                sub_mat(*x, *y, *z);
            }
            return;
        case MUL_MAT:
            if (x == NULL || y == NULL || z == NULL) {
                report_errors(MISSING_ARG_E);
            /* } else if (x == ILLEGAL_NAME || y == ILLEGAL_NAME || z == ILLEGAL_NAME) { */
            /*     report_errors(MISS_ARG_E); */
            } else {
                mul_mat(*x, *y, *z);
            }
            return;
        case MUL_SCALAR:
            if (x == NULL || y == NULL) {
                report_errors(MISSING_ARG_E);
            /* } else if (x == ILLEGAL_NAME || y == ILLEGAL_NAME) { */
            /*     report_errors(MISS_ARG_E); */
            } else {
                mul_scalar(*x, scalar, *y);
            }
            return;
        case TRANS:
            if (x == NULL || y == NULL) {
                report_errors(MISSING_ARG_E);
            /* } else if (x == ILLEGAL_NAME || y == ILLEGAL_NAME) { */
            /*     report_errors(MISS_ARG_E); */
            } else {
                trans_mat(*x, *y);
            }
            return;
        default:/* NULL_LINE */
            return;
    }
}

