#include <stdio.h>
#define ARR_MAX 1000

void sort_section(int *ptr, int *qtr);
void printf_array(int *ptr_head, int *ptr_end);

int main()
{
    int N, a, b;
    scanf("%d%d%d", &N, &a, &b);
    int arr[ARR_MAX] = {0};
    for (int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
    }
    sort_section(&arr[a], &arr[b]);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(arr + i));
    }
}

void sort_section(int *ptr, int *qtr)
{
    int *front, *end; //! 判斷頭尾
    if (ptr < qtr)
    {
        // printf("ptr is head\n");
        front = ptr;
        end = qtr;
    }
    else
    {
        // printf("qtr is head\n");
        front = qtr;
        end = ptr;
    }

    int *current_i = front;
    int *current_j = front;
    for (; current_i < end; current_i++)
    {
        for (; current_j < end; current_j++)
        {
            // printf("array[%d] = %d array[%d] = %d\n", current_j - front, *current_j, current_j + 1 - front, *(current_j + 1));
            if ((*(current_j + 1) < *current_j) && (current_j < end))
            {
                // printf("swap\n");
                int temp;
                temp = *current_j;
                *current_j = *(current_j + 1);
                *(current_j + 1) = temp;
            }
        }
        printf_array(front, end);
        printf("\n");
        current_j = front;
    }
}

void printf_array(int *ptr_head, int *ptr_end)
{
    for (ptr_head; ptr_head <= ptr_end; ptr_head++)
    {
        printf("%d ", *ptr_head);
    }
}