#include <stdio.h>
#define NAME_LEN 20

struct part
{
    int number;              //! 零件編號
    char name[NAME_LEN + 1]; //! 零件名字
    int on_hand;             //! 零件還剩幾個
};

typedef struct
{
    int array[10];
} array;

void Printf_Array(array a);

int main()
{
    struct part part1 = {.number = 528, .name = "Disk drive", .on_hand = 10};
    struct part part2 = {914, "Printer cable", 5};
    struct part part3;

    // todo : copy part1 to part3
    part3 = part1;

    printf("part1 %d %s on hand %d\n", part1.number, part1.name, part1.on_hand);
    printf("part3 %d %s on hand %d\n", part3.number, part3.name, part3.on_hand);

    array a1, a2;
    for (int i = 0; i < 10; i++)
        a1.array[i] = i;

    a2 = a1;

    Printf_Array(a1);
    puts("");
    Printf_Array(a2);

    return 0;
}

void Printf_Array(array a)
{
    for (int i = 0; i < 10; i++)
        printf("a[%d] = %d\n", i, a.array[i]);
}