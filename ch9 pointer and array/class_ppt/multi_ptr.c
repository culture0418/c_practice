#include <stdio.h>
#define ROWS 3
#define COLS 3

int main()
{
    int a[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &a[i][j]);

    for (int *p = a[1]; p < a[1] + COLS; p++)
        printf("%d ", *p);

    for (int(*p)[COLS] = &a[0]; p < &a[ROWS]; p++)
        printf("%d ", (*p)[0]);

    return 0;
}
