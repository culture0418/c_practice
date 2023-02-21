#include <stdio.h>

int main()
{
    float value[6][2];
    float sunday_price;

    scanf("%f", &sunday_price);

    // initialize
    value[0][0] = 0;
    value[0][1] = sunday_price;

    // printf("%f\n", value[0][1]);

    for (int i = 1; i < 6; i++)
    {
        value[i][0] = 0.9 * value[i - 1][1] + 0.1 * value[i - 1][0] - 51;
        value[i][1] = (-0.98) * value[i][0] + 153;
    }

    // output
    for (int k = 1; k < 6; k++)
    {
        printf("%.1f ", value[k][1]);
    }
}