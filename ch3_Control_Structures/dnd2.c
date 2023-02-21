#include <stdio.h>
#include <stdbool.h>

// todo: 有用到bool type 要記得 include <stdbool.h> !!!

bool Take_Turns(int, int, int);
int Player_Attack(int, int, int);
int Dragon_Attack(int, int, int);

int main()
{
    int dice[6];
    int player_point = 100;
    int dragon_point = 100;
    bool attack_flag; // true : player attack

    while ((player_point > 0) && (dragon_point > 0))
    {
        for (int i = 0; i < 6; i++)
        {
            scanf("%d", &dice[i]);
            // printf("%d ", dice[i]);
        }

        attack_flag = Take_Turns(dice[0], dice[1], dice[2]);

        if (attack_flag == true) // player attack
        {
            // printf("player attack\n");
            dragon_point = dragon_point - Player_Attack(dice[3], dice[4], dice[5]);
            // printf("dragon point = %d", dragon_point);
        }
        else // dragon attack
        {
            // printf("dragon attack\n");
            player_point = player_point - Dragon_Attack(dice[3], dice[4], dice[5]);
            // printf("player point = %d", player_point);
        }
    }

    // output
    if (dragon_point <= 0)
    {
        printf("Player wins\n");
        // printf("dragon point = %d", dragon_point);
    }
    if (player_point <= 0)
    {
        printf("Dragon wins\n");
        // printf("player point = %d", player_point);
    }
}

bool Take_Turns(int d1, int d2, int d3)
{
    if ((d1 + d2 + d3) % 2 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Player_Attack(int d4, int d5, int d6)
{
    if (d4 < d5 && d5 < d6) // critical
    {
        // printf("dragon -25\n");
        return 25;
    }
    else if ((d4 % 2 == d5 % 2) || (d5 % 2 == d6 % 2)) // normal
    {
        // printf("dragon -5\n");
        return 5;
    }
    else // miss
    {
        // printf("dragon -0\n");
        return 0;
    }
}

int Dragon_Attack(int d4, int d5, int d6)
{
    if ((d4 - d5) > d6 || ((d5 - d4) > d6)) // critical
    {
        // printf("player -15\n");
        return 15;
    }
    else if ((d4 + d5) != d6) // normal
    {
        // printf("player -5\n");
        return 5;
    }
    else // miss
    {
        // printf("player -0\n");
        return 0;
    }
}
