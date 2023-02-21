#include <stdio.h>

int main()
{
    int num[10];
    int *p = num;

    for (int i = 0; i < 10; i++)
        num[i] = i + 1;

    //! case : *p++  *(p++)
    // todo : 先做 *p 再做 p++;
    printf("*p++ = %d\n", *p++); //! printf 1
    printf("*p++ = %d\n", *p++); //! printf 2

    //! case : (*p)++
    // todo : 先做 *p 再做 (*p)++
    printf("(*p)++ = %d\n", (*p)++); //! printf 3
    printf("(*p)++ = %d\n", (*p)++); //! printf 4

    //! case : *++p  *(++p)
    // todo : 先做 ++p 再做 *p;
    printf("*++p = %d\n", *++p); //! printf 4
    printf("*++p = %d\n", *++p); //! printf 5

    //! case : ++*p  ++(*p)
    // todo : 先做 ++(*p) 再做 *p
    printf("++*p = %d\n", ++*p); //! printf 6
    printf("++*p = %d\n", ++*p); //! printf 7
    return 0;
}