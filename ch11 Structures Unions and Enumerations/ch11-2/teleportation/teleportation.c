#include <stdio.h>

unsigned long long construct(unsigned char parts[16]); //! 8 byte
union construct
{
    char p_array[8];
    unsigned long long full;
};

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%llu", construct(parts));

    return 0;
}

unsigned long long construct(unsigned char parts[16])
{
    union construct construct_num;

    for (int i = 0; i < 8; i++)
    {
        construct_num.p_array[i] = parts[i] ^ parts[i + 8];
    }
    return construct_num.full;
}