#include <stdio.h>

int Concat(int item_num);

int Concat_Array[50][50];

int main()
{
    int n_items;
    int total_concat_amount = 0;

    scanf("%d", &n_items);

    for (int i = 1; i <= n_items; i++)
    {
        scanf("%d", &Concat_Array[i][0]);
        if (Concat_Array[i][0] != 0)
        {
            for (int j = 1; j <= Concat_Array[i][0]; j++)
            {
                scanf("%d", &Concat_Array[i][j]);
            }
        }
    }

    for (int i = 1; i <= n_items; i++)
    {
        total_concat_amount += Concat(i);
        // printf("NO.%d need %d\n", i, total_concat_amount);
    }

    printf("%d", total_concat_amount);
    return 0;
}

int Concat(int item_num)
{
    int sum = 0;
    if (Concat_Array[item_num][0] == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= Concat_Array[item_num][0]; i++)
        {
            // printf("NO.%d\n", item_num);
            sum += Concat(Concat_Array[item_num][i]);
            // printf("NO.%d  no.%d sum = %d\n", item_num, i, sum);
        }
        return sum;
    }
}
