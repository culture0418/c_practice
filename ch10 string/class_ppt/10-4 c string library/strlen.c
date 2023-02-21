#include <stdio.h>
#include <string.h>
#define LENGTH 10
int main()
{
    // todo strlen 會 return unsigned integer 為字串長度大小(不包含\0)
    char str1[LENGTH + 1] = "abc";
    printf("length = %u\n", strlen(str1));

    return 0;
}