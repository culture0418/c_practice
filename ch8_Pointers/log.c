#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    scanf("%d", &num);
    printf("%d\n", lround(log2(num)));
    int exp = lround(log2(num));
    int exp_base127 = exp + 127;
    printf("exp127 = %d\n", exp_base127);

    int array[8];
    int i = 0;
    int num1_ide[32];
    int *num_ide = num1_ide;
    while (num > 0)
    {
        array[i] = num % 2;
        num = num / 2;
        i++;
    }
    int j = 1;
    for (; i > 0; i--)
    {
        num_ide[j] = array[i - 1];
        printf("%d", num_ide[j]);
        j++;
    }
    return 0;
}
