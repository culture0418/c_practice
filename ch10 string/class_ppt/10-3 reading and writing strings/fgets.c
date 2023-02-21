#include <stdio.h>
#include <string.h>

#define LENGTH 20
int main()
{
    char birthday[LENGTH + 1];
    fgets(birthday, LENGTH, stdin);
    puts(birthday);
    return 0;
}