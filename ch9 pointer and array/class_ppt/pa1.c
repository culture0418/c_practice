#include <stdio.h>
// #define w1
#define w2

int main()
{
    int num[10];
    int *p = num;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        num[i] = i + 1;
    }
//! 寫法一
#ifdef w1
    for (p = &num[0]; p < &num[10]; p++)
    {
        printf("p = %d\n", *p);
        sum += *p;
    }
#endif

//! 寫法二
#ifdef w2
    while (p < &num[10])
    {
        printf("p = %d\n", *p);
        sum += *p++;
        // todo : sum += *p;
        // todo : p++;
    }

#endif
    printf("sum = %d\n", sum);

    return 0;
}