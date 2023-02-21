#include <stdio.h>

typedef struct
{
    int i;
} test;

int main()
{
    test **t = (test **)malloc(20 * sizeof(test *));
    for (int i = 0; i < 20; ++i)
    {
        t[i] = (test *)malloc(20 * sizeof(test));
    }
}