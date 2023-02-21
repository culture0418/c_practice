// todo : input 10 numbers 反向輸入列印

#include <stdio.h>
#define N 5

int main()
{
    int num[N];
    int *ptr = num;
    for (ptr = num; ptr < num + N; ptr++)
        scanf("%d", ptr);

    printf("reverse order\n");

    for (ptr = num + N - 1; ptr >= num; ptr--)
        printf("%d ", *ptr);

    return 0;
}