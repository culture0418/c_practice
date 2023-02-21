#include <stdio.h>
#include <stdlib.h>

// #define DEBUG1
// #define DEBUG2

struct Car
{
    int passenger;
    int flammable;
    struct Car *next;
};

void attachCar(struct Car *head, int passenger, int flammable)
{
    struct Car *curr = head;
    while (curr->next)
        curr = curr->next; // Find the end of the train

    struct Car *newcar = malloc(sizeof(struct Car)); // todo : Make a new car
    newcar->passenger = passenger;                   // todo : Let passengers in
    newcar->flammable = flammable;                   // todo : Load flammable items
    newcar->next = NULL;                             // todo : This is the last car

    curr->next = newcar; // todo : Attach new car to the train
}

int fire(struct Car *head);

int main(int argc, char *argv[])
{
    int cars;
    int human[13], moeru[13];

    struct Car head;  //! 車頭
    head.next = NULL; // todo : passenger & flammable for head in useless

    scanf("%d", &cars);
    for (int i = 0; i < cars; ++i)
    {
        scanf("%d", &human[i]);
    }
    for (int i = 0; i < cars; ++i)
    {
        scanf("%d", &moeru[i]);
    }

    for (int i = 0; i < cars; ++i)
    {
        attachCar(&head, human[i], moeru[i]);
    }

    printf("%d", fire(&head)); //! The train is on fire now

    return 0;
}

// todo : 若該節車廂人數 >= 易燃物數量時，火勢便會停止蔓延，不會延燒到該節和後續的車廂
// todo : 但若人數不足，則車廂中所有人都會移往下一節車廂逃生
// todo : 直到延燒停止或所有乘客無處可逃並跳車為止。

int fire(struct Car *head)
{
    int on_fire = 0;
    struct Car *cur = head->next;

    while (cur != NULL)
    {
        if (cur->passenger >= cur->flammable)
            return on_fire;
        else
        {
            if (cur->next != NULL)
            {
                cur->next->passenger += cur->passenger;
                on_fire++;
            }
        }
        cur = cur->next;
    }
    on_fire++; // todo : 加上最後一節車廂
    return on_fire;
}