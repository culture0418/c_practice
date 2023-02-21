#include <stdio.h>
#include <string.h>
#define NAME_LEN 20

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

void printf_part(struct part part1);

int main()
{
    // todo : array 的 element 是 struct part
    struct part inventory[100];
    printf("enter part number : ");
    scanf("%d", &inventory[0].number);

    printf("enter part name :");
    fgets(inventory[0].name, NAME_LEN, stdin);

    printf("enter part on_hand quantity : ");
    scanf("%d", &inventory[0].on_hand);

    printf_part(inventory[0]);
}

void printf_part(struct part part1)
{
    printf("part number = %d\n", part1.number);
    printf("part name = %s\n", part1.name);
    printf("part on_hand quantity = %d\n", part1.on_hand);
}