#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s
{
    int weight;
    int value;
    struct node_s *next;
} node_t;

typedef struct prio_queue_s
{
    node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t *const queue, int value, int weight);
node_t *dequeue(prio_queue_t *const queue);
void print_nodes(const prio_queue_t *const queue);

int main()
{
    int N;
    scanf("%d", &N);
    prio_queue_t queue = {
        .head = NULL,
    };
    for (int i = 0; i < N; i++)
    {
        char op[8];
        scanf("%s", op);
        if (!strcmp(op, "ENQUEUE"))
        {
            int v, w;
            scanf("%d%d", &v, &w);
            enqueue(&queue, v, w);
        }
        else if (!strcmp(op, "DEQUEUE"))
        {
            free(dequeue(&queue));
        }
        print_nodes(&queue);
    }
    return 0;
}

void print_nodes(const prio_queue_t *const queue)
{
    if (!queue->head)
    {
        printf("EMPTY\n");
        return;
    }
    for (node_t *node = queue->head; node; node = node->next)
    {
        printf(" -> %d", node->value);
    }
    printf("\n");
    return;
}

// todo : 1. Priority Queue 中的每個節點皆包含兩個欄位：值（value）及權重（weight），且須以 linked-list 進行串接。
// todo : 2. 進行 enqueue 操作時以權重為排序依據，權重越小者越靠前面，且若權重相同，越先插入者越靠前。
// todo : 3. 進行 dequeue 操作時取出整個 Priority Queue 最前面的節點並將其回傳，若 Priority Queue 為空則回傳 NULL。
// todo : 4. 每次操作後從最前面開始將 Priority Queue 中的節點之值（value）印出。（Loader code 會處理）

void enqueue(prio_queue_t *const queue, int value, int weight)
{
    node_t *pre = NULL;
    node_t *insert = NULL;
    node_t *curr1 = queue->head; // todo : find insert
    node_t *curr2 = queue->head; // todo : find pre
    node_t *front = queue->head;
    node_t *rear = queue->head;

    while (rear)
        rear = rear->next;

    node_t *temp = malloc(sizeof(node_t));
    temp->value = value;
    temp->weight = weight;
    temp->next = NULL;

    //! case1 : priority queue 原本為空
    if (queue->head == NULL)
        queue->head = temp;
    else
    {
        // todo : find insert
        while (curr1 != NULL)
        {
            if (temp->weight < curr1->weight)
            {
                insert = curr1;
                break;
            }
            curr1 = curr1->next;
        }
        if (insert == NULL)
            insert = rear; //! 插入尾端
        //! case1 : 插入第一個
        if (insert == queue->head)
        {
            temp->next = queue->head;
            queue->head = temp;
        }
        else
        {
            // todo : find pre
            while (curr2 != NULL)
            {
                if (curr2->next == insert)
                    pre = curr2;
                curr2 = curr2->next;
            }
            //! case2 : 插入中間
            if ((insert != front) && (insert != rear))
            {
                temp->next = pre->next;
                pre->next = temp;
            }
            //! case3 : 插入尾端
            if (insert == rear)
            {
                pre->next = temp;
                rear = temp;
            }
        }
    }
}

node_t *dequeue(prio_queue_t *const queue)
{
    node_t *front = queue->head;
    //! case 1: priority queue 為空
    if (queue->head == NULL)
        return NULL;
    else
    {
        //! case 2: priority queue 中只有一個節點
        if (queue->head->next == NULL)
        {
            queue->head = NULL;
            return front;
        }
        else
        {
            //! case 3: priority queue 中有至少兩個節點
            queue->head = queue->head->next;
            return front;
        }
    }
}