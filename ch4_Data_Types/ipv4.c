#include <stdio.h>

int main()
{
    int hex;
    scanf("%x", &hex);
    int bit_gp1, bit_gp2, bit_gp3, bit_gp4;

    bit_gp1 = hex & 0x000000ff;
    bit_gp2 = (hex & 0x0000ff00) >> 8;
    bit_gp3 = (hex & 0x00ff0000) >> 16;
    bit_gp4 = (hex & 0xff000000) >> 24;

    // printf("%d ", bit_gp4);
    // printf("%d ", bit_gp3);
    // printf("%d ", bit_gp2);
    // printf("%d ", bit_gp1);

    printf("%d.%d.%d.%d", bit_gp4, bit_gp3, bit_gp2, bit_gp1);
    return 0;
}