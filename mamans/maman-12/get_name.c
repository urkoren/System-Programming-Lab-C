#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_NAMES   30
#define NAME_LEN    20

char names[NUM_NAMES][NAME_LEN];

char *get_name(void)
{   
    int index;
    index = (rand() % NUM_NAMES);
    return names[index];
}

int main(void)
{
    const int num_names_to_print = 10;

    int i, j;
    char *name;
    
    srand(time(0));
    memset(names,   0, sizeof(char) * NUM_NAMES  );
    memset(names[0],0, sizeof(char) * NAME_LEN  );

    for(i = 0; i < NUM_NAMES ; i++) {
        scanf("%s", names[i]);
        for (j = 0; names[i][j] != '\0'; j++) {
            names[i][j] = ((char)tolower(names[i][j]));
        }
    }

    for(i = 1; i < num_names_to_print+1; i++) {
        name = get_name();
        printf("Name %d = %s\n", i, name);
    }
    
    return 0;
}
