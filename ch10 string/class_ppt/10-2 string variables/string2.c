#include <stdio.h>
char digit_to_hex_char(int digit);
int main()
{
    // todo string literal
    char *p = "abc";

    //! wrong string literal can't modify
    // *p = 'd';

    printf("%c", digit_to_hex_char(10));

    return 0;
}

// todo string 可以利用 [index] 取出某一個 char
char digit_to_hex_char(int digit)
{
    return "0123456789ABCDEF"[digit];
}