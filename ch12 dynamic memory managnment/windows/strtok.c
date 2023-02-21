//! strtok 切割後 initial string 會被改變

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    char string[10] = "a p p l e";
    char *token = strtok(string, " ");
    printf("token = %s\n", token);
    printf("string = %s\n", string);

    token = strtok(NULL, " ");
    printf("token = %s\n", token);
    printf("string = %s\n", string);
    return 0;
}