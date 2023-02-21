#include <stdio.h>
#include <string.h>
#define LENGTH 10
int main()
{
    char str1[LENGTH + 1];
    char str2[LENGTH + 1];

    strncpy(str1, "abc", sizeof(str1) - 1);
    strncpy(str2, "def", sizeof(str2) - 1);

    // todo strncat(str1, str2, sizeof(str1) - strlen(str1) - 1)
    // todo 全部長度 - 裡面已經存的字串 - \0
    strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
    puts(str1);
    return 0;
}