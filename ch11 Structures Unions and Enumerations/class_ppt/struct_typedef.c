#include <stdio.h>
#include <string.h>
#define NAME_LEN 20

typedef struct
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part;

void Printf_Part(part p);
part build_part(int number, const char *name, int on_hand);

int main()
{
    part p1 = build_part(528, "disk driver", 10);
    Printf_Part(p1);
    return 0;
}

void Printf_Part(part p)
{
    printf("part number = %d\n", p.number);
    printf("part name = %s\n", p.name);
    printf("quantity on hand = %d\n", p.on_hand);
}

part build_part(int number, const char *name, int on_hand)
{
    part p;
    p.number = number;
    strcpy(p.name, name);
    p.on_hand = on_hand;
    return p;
}