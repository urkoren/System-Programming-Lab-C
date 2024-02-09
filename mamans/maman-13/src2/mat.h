#ifndef MAT_H_
#define MAT_H_

#define MAT_SIZE 4

#define GENERATOR(GENERATE_BEGIN, GENERATE, GENERATE_END)\
    GENERATE_BEGIN\
    GENERATE(MAT_A)\
    GENERATE(MAT_B)\
    GENERATE(MAT_C)\
    GENERATE(MAT_D)\
    GENERATE(MAT_E)\
    GENERATE(MAT_F)\
    GENERATE_END

typedef struct matrix_s {
    float 
    data[MAT_SIZE][MAT_SIZE];
} mat;

#define\
    GENERATE_MATRICES_BEGIN\
    typedef struct matrices_s {
#define\
    GENERATE_MATRICES(X)\
    mat X;\
    const char *X##_name = #X;
#define\
    GENERATE_MATRICES_END\
    } MATRICES;

GENERATOR(GENERATE_MATRICES_BEGIN, GENERATE_MATRICES, GENERATE_MATRICES_END)

#endif
