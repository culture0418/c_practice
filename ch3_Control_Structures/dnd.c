#include <stdio.h>

int main()
{

    int d1, d2, d3, d4, d5, d6;
    scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);

    if ((d1 + d2 + d3) < 11)
    { // player attacks
        if ((d4 == d5) && (d5 == d6))
        { // critical hit
            printf("Player attacks: Critical Hit");
        }
        else if ((d4 + d5 > d6) || (d4 + d5 == d6))
        { // normal hit
            printf("Player attacks: Normal Hit");
        }
        else
        { // miss
            printf("Player attacks: Miss");
        }
    }
    else
    { // Dragon attacks
        if ((d4 == d5) || (d4 == d6) || (d5 == d6))
        { // miss
            printf("Dragon attacks: Miss");
        }
        else if (d4 + d5 != d6)
        { // normal hit
            printf("Dragon attacks: Normal Hit");
        }
        else
        { // critical hit
            printf("Dragon attacks: Critical Hit");
        }
    }
}