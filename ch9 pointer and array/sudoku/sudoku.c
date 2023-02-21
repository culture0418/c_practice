#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);
void check_row(int (*grid_p_row)[NUM], int (*flag_row)[NUM]);
void check_column(int (*grid_p_col)[NUM], int (*flag_col)[NUM]);
void check_square(int (*grid_p_square)[NUM], int (*flag_square)[NUM]);
void printf_flag(int (*flag_all)[NUM]);

int main(void)
{
    int grid[NUM][NUM]; // sudoku puzzle
    for (int i = 0; i < NUM; ++i)
    {
        for (int j = 0; j < NUM; ++j)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    check_sudoku(grid); //! pointer to grid[0]   (first row)

    return 0;
}

void check_sudoku(int (*grid_p)[NUM])
{
    int flag_array[9][9] = {0};
    check_row(grid_p, flag_array);
    check_column(grid_p, flag_array);
    check_square(grid_p, flag_array);
    printf_flag(flag_array);
}

void check_row(int (*grid_p_row)[NUM], int (*flag_row)[NUM])
{
    int num;
    int(*flag_original)[NUM] = flag_row;
    int flag[2][10];
    for (int k = 0; k < 2; k++) // todo : initialize flag[10]
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    for (int i = 0; i < NUM; i++) //! i: row
    {
        for (int j = 0; j < NUM; j++) //! j: column
        {
            num = (*grid_p_row)[j];
            if (flag[0][num] != -1) //! 這個數字有出現過了
            {
                // printf("repeat number in same row\n");
                int row = flag[0][num];
                int col = flag[1][num];

                flag_row = flag_row + row;
                (*flag_row)[col]++;
                flag_row = flag_original;

                flag_row = flag_row + i;
                (*flag_row)[j]++;
                flag_row = flag_original;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        for (int k = 0; k < 2; k++) // todo : initialize flag[10]
        {
            for (int m = 0; m < 10; m++)
            {
                flag[k][m] = -1;
            }
        }
        grid_p_row++;
    }
}

void check_column(int (*grid_p_col)[NUM], int (*flag_col)[NUM])
{
    int num;
    int(*flag_original)[NUM] = flag_col;
    int(*grid_col_original)[NUM] = grid_p_col;

    int flag[2][10];
    for (int k = 0; k < 2; k++) // todo : initialize flag[10]
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    for (int j = 0; j < NUM; j++) //! j: column
    {
        for (int i = 0; i < NUM; i++) //! i:row
        {
            num = (*grid_p_col)[j];
            if (flag[0][num] != -1) //! 數字出現過
            {
                int row = flag[0][num];
                int col = flag[1][num];

                flag_col = flag_col + row;
                (*flag_col)[col]++;
                flag_col = flag_original;

                flag_col = flag_col + i;
                (*flag_col)[j]++;
                flag_col = flag_original;
            }
            flag[0][num] = i;
            flag[1][num] = j;

            grid_p_col++;
        }
        for (int k = 0; k < 2; k++) // todo : initialize flag[10]
        {
            for (int m = 0; m < 10; m++)
            {
                flag[k][m] = -1;
            }
        }
        grid_p_col = grid_col_original;
    }
}

void check_square(int (*grid_p_square)[NUM], int (*flag_square)[NUM]) //! fix square check
{
    int flag[2][10];
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    int num;
    // todo: check block1
    for (int i = 0; i < 3; i++)
    { //! i : 橫列
        for (int j = 0; j < 3; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    // todo: check block2
    for (int i = 3; i < 6; i++)
    { //! i : 橫列
        for (int j = 0; j < 3; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    // todo: check block3
    for (int i = 6; i < 9; i++)
    { //! i : 橫列
        for (int j = 0; j < 3; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    grid_p_square = grid_p_square - NUM;

    // todo: check block4
    for (int i = 0; i < 3; i++)
    { //! i : 橫列
        for (int j = 3; j < 6; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    // todo: check block5
    for (int i = 3; i < 6; i++)
    { //! i : 橫列
        for (int j = 3; j < 6; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    // todo: check block6
    for (int i = 6; i < 9; i++)
    { //! i : 橫列
        for (int j = 3; j < 6; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    grid_p_square = grid_p_square - NUM;

    // todo: check block7
    for (int i = 0; i < 3; i++)
    { //! i : 橫列
        for (int j = 6; j < 9; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    // todo: check block8
    for (int i = 3; i < 6; i++)
    { //! i : 橫列
        for (int j = 6; j < 9; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
    for (int k = 0; k < 2; k++) // todo : flag[2][10] initialize
    {
        for (int m = 0; m < 10; m++)
        {
            flag[k][m] = -1;
        }
    }

    // todo: check block9
    for (int i = 6; i < 9; i++)
    { //! i : 橫列
        for (int j = 6; j < 9; j++)
        { //! j: 直行
            num = (*grid_p_square)[j];
            if (flag[0][num] != -1)
            { //! 數字第二次出現
                int row = flag[0][num];
                int col = flag[1][num];

                flag_square = flag_square + row;
                (*flag_square)[col]++;
                flag_square = flag_square - row;

                flag_square = flag_square + i;
                (*flag_square)[j]++;
                flag_square = flag_square - i;
            }
            flag[0][num] = i;
            flag[1][num] = j;
        }
        grid_p_square++;
    }
}

void printf_flag(int (*flag_all)[NUM])
{
    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM; j++)
        {
            if ((*flag_all)[j] > 0)
            {
                printf("(%d,%d)\n", i, j);
            }
            // printf("%d ", (*flag_all)[j]);
        }
        // printf("\n");
        flag_all++;
    }
}