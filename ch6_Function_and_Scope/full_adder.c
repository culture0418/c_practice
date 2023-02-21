#include <stdio.h>

#define LEN 5

int full_adder_c(int a, int b, int c);
int full_adder_x(int a, int b, int c);

int main()
{
    int a[LEN], b[LEN], ans[LEN], c = 0;
    for (int i = 0; i < LEN; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < LEN; ++i)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < LEN; ++i)
    {
        ans[i] = full_adder_x(a[i], b[i], c);
        c = full_adder_c(a[i], b[i], c);
    }
    for (int i = 0; i < LEN; ++i)
    {
        printf("%d ", ans[i]);
    }
    printf("%d", c);
}

int full_adder_c(int a, int b, int c) // carry
{
    int carry;
    carry = a + b + c;
    if ((carry / 2) > 0)
    {
        carry = 1;
    }
    else
    {
        carry = 0;
    }

    return carry;
}

int full_adder_x(int a, int b, int c) // sum
{
    int sum;
    sum = a + b + c;
    if ((sum % 2) == 0)
    {
        sum = 0;
    }
    else
    {
        sum = 1;
    }

    return sum;
}
