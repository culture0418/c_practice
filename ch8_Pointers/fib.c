#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{

    if (k == 1)
    {
        *f2k = 1;
        *f2k1 = 2;
    }
    else
    {
        if ((k % 2) == 0)
        {
            k = k / 2;
            fib_fast_doubling(k, f2k, f2k1);
            uint64_t f2k_num = *f2k;
            uint64_t f2k1_num = *f2k1;

            *f2k = f2k_num * (2 * f2k1_num - f2k_num);
            *f2k1 = f2k_num * f2k_num + f2k1_num * f2k1_num;
        }
        else
        {
            k = k / 2;
            fib_fast_doubling(k, f2k1, f2k);
            uint64_t f2k_num = *f2k1;
            uint64_t f2k1_num = *f2k;

            *f2k = f2k_num * (2 * f2k1_num - f2k_num);
            *f2k1 = f2k_num * f2k_num + f2k1_num * f2k1_num;
        }
    }
}