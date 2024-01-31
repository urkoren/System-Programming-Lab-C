#include <stdio.h>

#define bufsize 25
#define cmd_fmt "%4[a-zA-Z]"
#define mat_fmt "%4[a-zA-Z]"
#define mat_sep ","
#define scan_format  "%s %s , %s , %s"

void skip_to_newline()
{
    char c[4] = {0};
    scanf("%c%*[^,]%c%*[^\n]",c, c+2);
    printf("%s", c);
}

/* char skip_whitespace()
{
    char c;
    while (isspace(c = getchar()) && c != '\n');
}
 */
int main(int argc, char **argv)
{
    char cmd_buf[bufsize] = {0};
    char mat_buf[bufsize][3] = {{0}, {0}, {0}};
    int res;

/*     printf("Enter cmd (cmd mat, mat, mat): ");
    res = scanf( cmd_fmt, cmd_buf);
    printf(
        "cmd: %s, mat_a: %s, mat_b: %s, mat_c: %s\n",
        cmd_buf, mat_buf[0], mat_buf[1], mat_buf[2]
    );
    printf("res: %d\n", res);
 */
    skip_to_newline();
    return 0;
}
