#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void MoveToTail();

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        struct node *tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if (i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for (struct node *cur = head; cur != NULL; cur = cur->next)
    {
        printf("%d ", cur->val);
    }
    return 0;
}

void MoveToTail()
{
    struct node *max = head;
    struct node *cur1 = head; // todo : 用來找max
    struct node *cur2 = head; // todo : 用來找pre
    struct node *pre = NULL;

    // todo : 找max
    while (cur1 != NULL)
    {
        if (cur1->val > max->val)
        {
            max = cur1;
        }
        cur1 = cur1->next;
    }

    //! case1 : max 在 1st
    if (max == head)
    {
        head = head->next;
        tail->next = max;
        tail = tail->next;
        tail->next = NULL;
    }

    //! case2 : max 在 中間 fixme!!!!
    if ((max != head) && (max != tail))
    {
        // todo: find pre
        while (cur2 != tail)
        {
            if ((cur2->next)->val == max->val)
            {
                pre = cur2;
            }
            cur2 = cur2->next;
        }

        pre->next = max->next;
        tail->next = max;
        tail = tail->next;
        tail->next = NULL;
    }
}