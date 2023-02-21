#include <stdio.h>

int main()
{
    int num_array[50];
    int i = 0;
    int max, min;
    do
    {
        scanf("%d", &num_array[i]);
        i++;
        // printf("%d", i);
    } while (num_array[i - 1] != -1);

    // printf("%d", i);

    max = num_array[0];
    min = num_array[0];

    for (int j = 0; j < i - 1; j++)
    {
        if (num_array[j] > max)
        {
            max = num_array[j];
        }
        else
        {
            if (num_array[j] < min)
            {
                min = num_array[j];
            }
        }
    }

    printf("%d", (max - min));
}