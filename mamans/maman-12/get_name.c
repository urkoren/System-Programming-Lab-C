#include "get_name.h"

int main(void)
{
    const int num_names_to_print = 10;

    int i;
    char *name;
    
    /* Create seed of current time */
    srand(time(0));

    if (insert_names() == 0){
        /* Loop that print random names in range of constant */
        for(i = 1; i < num_names_to_print+1; i++) {
            name = get_name();
            printf("Name %d = %s\n", i, name);
        }
    }
    return 0;
}
