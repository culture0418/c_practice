#include <stdio.h>
#define N 10
int main()
{
    int a[N];
    int *ptr = a;
    int sum = 0;

    for (int i = 0; i < N; i++)
        a[i] = i + 1;
    for (ptr = a; ptr < a + N; ptr++)
        sum += *ptr;
    printf("sum = %d\n", sum);

    return 0;
}