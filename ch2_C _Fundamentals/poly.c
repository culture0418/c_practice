#include <stdio.h>
#include <math.h>

int main(void)
{
    float num1, result;
    scanf("%f", &num1);

    // 𝟕𝐱⁴ - 𝟖𝐱³ - 𝐱² + 𝟔𝐱 - 𝟐𝟐
    result = 7 * pow(num1, 4) - 8 * pow(num1, 3) - pow(num1, 2) + 6 * num1 - 22;

    printf("%.1f", result);
    return 0;
}