#include <stdio.h>

int main()
{
    int d1, d2;
    int dice[6] = {0};

    for (int i = 0; i < 75; i++)
    {
        scanf("%d %d", &d1, &d2);

        if ((d2 % 2) != 0) // d2 odd +
        {
            if (dice[d1 - 1] == 9)
            {
                dice[d1 - 1] = 0;
            }
            else
            {
                dice[d1 - 1]++;
            }
        }
        else // d2 even -
        {
            if (dice[d1 - 1] == 0)
            {
                dice[d1 - 1] = 9;
            }
            else
            {
                dice[d1 - 1]--;
            }
        }

        // for (int i = 0; i < 6; i++)
        // {
        //     printf("%d ", dice[i]);
        // }
        // printf("\n");
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", dice[i]);
    }
}