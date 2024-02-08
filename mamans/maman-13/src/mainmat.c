#include <stdio.h>
#include "mymat.h"
#include "analyze.h"
#include "io.h"
#include "command.h"

int main(void) {
    mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;
    MATRICES mats;
    mats.MAT_A = &MAT_A;
    mats.MAT_B = &MAT_B;
    mats.MAT_C = &MAT_C;
    mats.MAT_D = &MAT_D;
    mats.MAT_E = &MAT_E;
    mats.MAT_F = &MAT_F;

    int status = 0;
    MAT_ARGS args = {0};

    init_mats(mats);
    char line[LINE_SIZE];    
    Command command;    
    double scalar = 0;/* var for mul_scalar */
    double arg_values[MAT_SIZE];
    Error error = NONE;

    while (status != -1) {
        printf(">>> ");/* prompt to indicate that the calculatour is ready for a new command.*/
        status = get_line(line, &error);/* 0 = good, -1 = EOF */
        if (status != 0) {
            printf("Error: EOF has entered ");
            return EXIT_FAILURE;
        }
        print_line(line);
        report_errors(error);

        analyze(line, &command, args ,arg_values, &scalar, &error, mats);
        if (error != NONE) {
            report_errors(error);
        } else {/* error == NONE */
            do_command(command, args, &mats, scalar, arg_values);
        }
        error = NONE;
    }/* while */
    stop();

    return 0;
}

