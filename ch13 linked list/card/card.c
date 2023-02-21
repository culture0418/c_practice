#include <stdio.h>
#include <stdlib.h>

struct card
{
    int number;
    struct card *next;
};

void new_card(struct card *card1, int num);
void play_card(struct card *card1, int round);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct card *card1 = malloc(sizeof(struct card));
    card1->number = 1;
    card1->next = NULL;

    for (int i = 2; i <= n; i++)
    {
        new_card(card1, i);
    }

    play_card(card1, m);

    return 0;
}

void new_card(struct card *card1, int num)
{
    struct card *ptr = card1;
    while (ptr->next)
        ptr = ptr->next;

    struct card *new_card = malloc(sizeof(struct card));
    new_card->number = num;
    new_card->next = NULL;
    ptr->next = new_card;
}

void play_card(struct card *card1, int round)
{
    struct card *top = card1;
    struct card *last = card1;

    while (last->next)
        last = last->next;

    while (round > 0)
    {
        round--;
        printf("%d ", top->number);

        top = top->next;
        // todo : 加到最後面
        last->next = top;
        last = last->next;
        top = top->next;
    }
}