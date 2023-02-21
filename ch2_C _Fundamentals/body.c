#include <stdio.h>
#include <math.h>

int main(void)
{
    int weight, height;
    float bmi, height_m;
    scanf("%d %d", &height, &weight); // input weight: kg, height: cm

    // unit translate
    height_m = height / 100.0;

    bmi = weight / (height_m * height_m);
    printf("%.6f", bmi);
    return 0;
}