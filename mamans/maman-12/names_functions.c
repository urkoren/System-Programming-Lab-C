#include "get_name.h"

char names[NUM_NAMES][NAME_LEN];



char *get_name(void)
/* Function that return a random name out of names array */
{   
    int index;
    index = (rand() % NUM_NAMES);
    return names[index];
}

int insert_names(void)
{
    /* Scan 30 names into names while making it lower case and 
                                    checking for duplicats*/
    int i,j,k;
    char temp_name[NAME_LEN] = "0";

    /* Sets whole names array to 0 */
    memset(names,   0, sizeof(char) * NUM_NAMES  );
    memset(names[0],0, sizeof(char) * NAME_LEN  );

    for(i = 0; i < NUM_NAMES ; i++) {
        scanf("%s", temp_name);

        /* converts to lower */
        for (j = 0; temp_name[j] != '\0'; j++) {
            temp_name[j] = ((char)tolower(temp_name[j]));
        }

        /* checks for duplicats */
        for (k = 0; k < i; k++){
            if (strcmp(temp_name,names[k]) == 0){
                printf("Error: The name '%s' is already in the list.\n"
                "Duplicate names are not allowed.\n", temp_name);
                return 1;
            }
        }
        strcpy(names[i],temp_name);
    }
    return 0;
}

