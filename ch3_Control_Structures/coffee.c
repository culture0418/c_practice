#include <stdio.h>
#define AMERICANO 110
#define LATTE 150
#define CAPPUCCINO 135
#define MOCHA 145

int main()
{
    int coffee_num, cup, total;
    scanf("%d %d", &coffee_num, &cup);

    switch (coffee_num)
    {
    case 1:
        total = AMERICANO * cup;
        break;
    case 2:
        total = LATTE * cup;
        break;
    case 3:
        total = CAPPUCCINO * cup;
        break;
    case 4:
        total = MOCHA * cup;
        break;

    default:
        break;
    }

    if (coffee_num < 1 || coffee_num > 4)
    { // exception
        printf("Wait, what?");
    }
    else
    {
        printf("The total price is %d dollars!", total);
    }

    return 0;
}