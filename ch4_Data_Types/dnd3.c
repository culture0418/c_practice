#include <stdio.h>
#include <limits.h>

#define NUMBER_1 0x38E38E38E38E3800LLU // 4099276460824344026
#define NUMBER_2 0x2AAAAAAAAAAAAAAALLU // 3074457345618258462
#define NUMBER_3 0x1C71C71C71C71C71LLU // 2049638230412172068
#define DIVISOR 0x7CE66C50E2840000LLU  // 9000000000000000000

int main()
{
    unsigned int dice_1, dice_2, dice_3;
    unsigned long long int a, b, c, output; // 8 bytes
    scanf("%u %u %u", &dice_1, &dice_2, &dice_3);

    // (d1 * NUMBER_1 + d2 * NUMBER_2 + d3 * NUMBER_3) mod 0x7CE66C50E2840000LLU
    a = (dice_1 * NUMBER_1);
    b = (dice_2 * NUMBER_2);
    c = (dice_3 * NUMBER_3);

    a = a % DIVISOR;
    b = b % DIVISOR;
    c = c % DIVISOR;

    // printf("dice1 * number1 = %llu\n", dice_1 * NUMBER_1);
    // printf("dice2 * number2 = %llu\n", dice_2 * NUMBER_2);
    // printf("dice3 * number3 = %llu\n", dice_3 * NUMBER_3);

    // printf("a = %llu\n", a);
    // printf("b = %llu\n", b);
    // printf("c = %llu\n", c);
    // printf("sum = %llu\n", a + b + c);

    // (a + b) % c = ((a % c) + (b % c)) % c
    output = (a + ((b + c) % DIVISOR)) % DIVISOR;
    printf("%llu", output);
}