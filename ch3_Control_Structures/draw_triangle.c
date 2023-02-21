#include <stdio.h>

int main()
{
    int choice, level;
    scanf("%d %d", &choice, &level);

    switch (choice)
    {
    case 1: // 左上直角三角形
        for (int i = 0; i < level; i++)
        {
            for (int j = 0; j < (level - i); j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    case 2: // 左下直角三角形
        for (int i = 0; i < level; i++)
        {
            for (int j = 0; j < (i + 1); j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    case 3: // 右上直角三角形
        for (int i = 0; i < level; i++)
        {
            for (int j = 0; j < i; j++)
            {
                printf(" ");
            }

            for (int k = 0; k < level - i; k++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    case 4: // 右下直角三角形
        for (int i = 0; i < level; i++)
        {
            for (int k = 0; k < level - i - 1; k++)
            {
                printf(" ");
            }

            for (int j = level - i - 1; j < level; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    default:
        break;
    }
}