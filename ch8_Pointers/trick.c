#include <stdio.h>
#include <stdlib.h>
int array[1500];
int maxChandy(int size);
int main()
{
    int size = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy(size));
    return 0;
}

int maxChandy(int size)
{
    int sum_array[size];
    sum_array[0] = array[0];
    for (int i = 1; i < size; i++)
    {
        if (i - 2 < 0)
        {
            sum_array[i] = max(array[i], array[0]);
        }
        else
        {
            sum_array[i] = max(sum_array[i - 1], max(array[i], array[i] + sum_array[i - 2]));
        }
    }

    // for (int i = 0; i < size; i++)
    // {
    //     printf("sum[%d] = %d\n", i, sum_array[i]);
    // }

    // printf("return value = %d\n", sum_array[size]);
    return sum_array[size - 1];
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}