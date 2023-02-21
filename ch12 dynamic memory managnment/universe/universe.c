#include <stdio.h>
#include <stdlib.h>
void init(int ****ptr);

int main()
{
    int ****ptr = malloc(sizeof(int ***) * 2);
    init(ptr);
    int magic_number;
    long long magic_sum = 0;
    scanf("%d", &magic_number);
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int c = 0; c < 2; c++)
                for (int d = 0; d < 2; d++)
                    ptr[a][b][c][d] = magic_number, magic_sum += ptr[a][b][c][d];
    printf("%lld", magic_sum);
}

void init(int ****ptr)
{
    ptr[0] = malloc(sizeof(int **) * 2);
    ptr[1] = malloc(sizeof(int **) * 2);

    ptr[0][0] = malloc(sizeof(int *) * 2);
    ptr[0][1] = malloc(sizeof(int *) * 2);
    ptr[1][0] = malloc(sizeof(int *) * 2);
    ptr[1][1] = malloc(sizeof(int *) * 2);

    ptr[0][0][0] = malloc(sizeof(int) * 2);
    ptr[0][0][1] = malloc(sizeof(int) * 2);
    ptr[0][1][0] = malloc(sizeof(int) * 2);
    ptr[0][1][1] = malloc(sizeof(int) * 2);

    ptr[1][0][0] = malloc(sizeof(int) * 2);
    ptr[1][0][1] = malloc(sizeof(int) * 2);
    ptr[1][1][0] = malloc(sizeof(int) * 2);
    ptr[1][1][1] = malloc(sizeof(int) * 2);
}