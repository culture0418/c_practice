#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NAME_LEN 20

int main()
{
    char *str1_ptr = malloc(NAME_LEN + 1);

    char *str2_ptr = NULL;
    str2_ptr = (char *)malloc(NAME_LEN + 1);
    strcpy(str2_ptr, "abc");
    printf("%s\n", str2_ptr);
}