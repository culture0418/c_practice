#include <stdio.h>
#include <string.h>
#define NAME_LEN 20

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

void Printf_Part(struct part p);
struct part build_part(int number, const char *name, int on_hand);

int main()
{
    struct part part1 = build_part(528, "disk driver", 10);
    Printf_Part(part1);
}

void Printf_Part(struct part p)
{
    printf("part number = %d\n", p.number);
    printf("part name = %s\n", p.name);
    printf("quantity on hand = %d\n", p.on_hand);
}

struct part build_part(int number, const char *name, int on_hand)
{
    struct part p;
    p.number = number;
    strcpy(p.name, name);
    p.on_hand = on_hand;
    return p;
}