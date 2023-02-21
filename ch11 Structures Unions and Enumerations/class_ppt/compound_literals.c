#include <stdio.h>
#define NAME_LEN 10
struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

void printf_part(struct part part1);

int main()
{
    printf_part((struct part){.number = 528, .name = "disk driver", .on_hand = 10});
    return 0;
}

void printf_part(struct part part1)
{
    printf("part number = %d\n", part1.number);
    printf("part name = %s\n", part1.name);
    printf("quantity on hand = %d\n", part1.on_hand);
}