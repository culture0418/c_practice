#include <stdio.h>
#include <math.h>
#define SQUARE_3 1.7320508f

int main(void)
{
    int length;
    float area;

    scanf("%d", &length);
    area = SQUARE_3 / 4.0 * pow(length, 2);
    printf("%.3f", area);

    return 0;
}