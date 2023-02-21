#include <stdio.h>
#include <stdbool.h>

int Check_Bingo(int Host[], int Bingo[8][8]);
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

    line_cnt = Check_Bingo(Host, Bingo);
    printf("%d", line_cnt);

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
}

int Check_Bingo(int Host[], int Bingo[8][8])
{
    static int Bingo_Boolean[8][8] = {0};
    for (int k = 0; k < 64; k++)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (Host[k] == Bingo[i][j])
                {
                    Bingo_Boolean[i][j] = 1;
                    break;
                }
            }
        }
    }

    int cnt = 0;
    int line = 0;

    // check row
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Bingo_Boolean[i][j] == 1)
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

    // check column
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Bingo_Boolean[j][i] == 1)
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

    // check right-diagonal
    for (int i = 0; i < 8; i++)
    {
        if (Bingo_Boolean[i][i] == 1)
        {
            cnt++;
        }
    }
    if (cnt == 8)
    {
        line++;
    }
    cnt = 0;

    // check left-diagonal
    for (int i = 0; i < 8; i++)
    {
        if (Bingo_Boolean[i][7 - i] == 1)
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
