#include <stdio.h>
#include <string.h>

//! strlen 印出來的數字為字串長度 不包含'\0'

int main()
{
    char a[20] = "c is funny!!!";
    char b[20] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};
    char *a_ptr = a;
    // using the %zu format specifier to print size_t
    printf("Length of string a = %zu \n", strlen(a_ptr));
    printf("Length of string b = %zu \n", strlen(b));

    return 0;
}