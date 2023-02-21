#include <stdio.h>
#include <stdlib.h>

struct ESPer
{
    char name[64];
    int level;
};

int cmp(const void *a, const void *b);
void sort_level(struct ESPer *arr, int length);

int main()
{
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }

    sort_level(tokiwadai, n);

    for (int i = 0; i < n; ++i)
    {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }

    return 0;
}

void sort_level(struct ESPer *arr, int length)
{
    struct ESPer ans_arr[100];
    int level[length];
    for (int i = 0; i < length; i++)
    {
        level[i] = arr[i].level;
    }

    qsort(level, length, 4, cmp);
    //! fixme

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (arr[j].level == level[i])
            {
                ans_arr[i] = arr[j];
                break;
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        arr[i] = ans_arr[i];
    }
}

int cmp(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
    {
        return -1;
    }
    else if (num1 == num2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
