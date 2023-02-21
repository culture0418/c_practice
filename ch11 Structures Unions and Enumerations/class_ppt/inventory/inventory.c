#include <stdio.h>
#include "readline.h"

struct part inventory[100];
int num_parts = 0; //! number of parts currently store

int main()
{
    char code;
    for (;;)
    {
        printf("enter operation code : ");
        scanf("%c", &code);
        while (getchar() != '\n')
            ; // todo : skip to end of line
        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'q':
            return 0;
        default:
            printf("illegal code\n");
            break;
        }
        puts("");
    }
}

void insert(void)
{
    int part_number;
    if (num_parts == MAX_PARTS)
    {
        printf("database is full; can't add more parts\n");
        return;
    }
    printf("enter part number : ");
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0)
    {
        printf("part already exists.\n");
        return;
    }

    // todo : insert at the end
    inventory[num_parts].number = part_number;
    printf("enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("enter quantity on hand : ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

void search(void)
{
    int i, number;

    printf("enter part number : ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0)
    {
        printf("part name : %s\n", inventory[i].name);
        printf("on hand quantity : %d\n", inventory[i].on_hand);
    }
    else
        printf("part not found\n");
}

void update()
{
    int i, number, change;
    printf("enter part number : ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0)
    {
        printf("enter change in quantity on hand : ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
        printf("part not found\n");
}

void print()
{
    printf("Part number     Part name       Quantity on hand");
    for (int i = 0; i < num_parts; i++)
        printf("%7d     %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

int find_part(int number)
{
    for (int i = 0; i < num_parts; i++)
    {
        if (inventory[i].number == number)
            return i;
    }
    return -1;
}