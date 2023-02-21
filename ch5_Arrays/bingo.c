#include <stdio.h>
#include <stdbool.h>

// FIXME: THIS VERSION IS WRONG VERSION !!!

int *Check_Bingo(int Host[], int Bingo[8][8]);
int Check_Line(int *Bingo_Boolean);

int main()
{
    int Bingo[8][8];
    int Host[64];
    int line_cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%d", &Bingo[i][j]);
        }
    }

    for (int i = 0; i < 64; i++)
    {
        scanf("%d", &Host[i]);
    }

    int *bingo_bool_ptr = Check_Bingo(Host, Bingo);
    // for (int i = 0; i < 64; i++)
    // {
    //     if ((i % 8) == 7)
    //     {
    //         printf("%d ", bingo_bool_ptr[i]);
    //         printf("\n");
    //     }
    //     else
    //     {
    //         printf("%d ", bingo_bool_ptr[i]);
    //     }
    // }
    line_cnt = Check_Line(bingo_bool_ptr);
    printf("%d", line_cnt);
}

int *Check_Bingo(int Host[], int Bingo[8][8])
{
    static int Bingo_Boolean[64] = {0};
    for (int k = 0; k < 64; k++)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (Host[k] == Bingo[i][j])
                {
                    Bingo_Boolean[8 * i + j] = 1;
                }
            }
        }
    }
    return Bingo_Boolean;
}

int Check_Line(int *Bingo_Boolean)
{
    int cnt = 0;
    int line = 0;

    for (int i = 0; i < 64; i++) // check row
    {
        if (Bingo_Boolean[i] == 1)
        {
            cnt++;
        }
        if ((i % 8) == 7)
        {
            if (cnt == 8)
            {
                line++;
            }
            cnt = 0;
        }
    }

    for (int i = 0; i < 8; i++) // check column
    {
        for (int j = 0; j < 8; j++)
        {
            if (Bingo_Boolean[i + 8 * j] == 1)
            {
                cnt++;
            }
        }
        if (cnt == 8)
        {
            line++;
        }
        cnt = 0;
    }

    for (int i = 0; i < 8; i++)
    {
        if (Bingo_Boolean[9 * i] == 1)
        {
            cnt++;
        }
    }
    if (cnt == 8)
    {
        line++;
    }
    cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        if (Bingo_Boolean[7 * i] == 1)
        {
            cnt++;
        }
    }
    if (cnt == 8)
    {
        line++;
    }
    cnt = 0;
    return line;
}