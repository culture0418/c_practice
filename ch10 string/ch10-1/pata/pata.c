#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1024

int main()
{
    int distance;
    int monster_blood;
    int cmd_cnt = 0;
    int legal_cmd = 0;
    char command[MAX_SIZE + 1];
    char move1[] = "PATA PATA PATA PON";
    char attack1[] = "PON PON PATA PON";
    char defend[] = "CHAKA CHAKA PATA PON";
    char *token;
    bool defend_flag = false;
    bool monster_kill = false;

    scanf("%d", &distance);
    scanf("%d ", &monster_blood);
    gets(command);

    token = strtok(command, ",.");
    while (token != NULL)
    {
        cmd_cnt++;
        // printf("cmd%d : %s\n", cmd_cnt, token);
        // todo: 判斷當前指令動作
        if (strcmp(token, move1) == 0)
        {
            legal_cmd++;
            // printf("move1\n");
            distance--;
            // printf("current distance = %d\n", distance);
        }
        if (strcmp(token, attack1) == 0)
        {
            legal_cmd++;
            // printf("attack check distance\n");
            // printf("distance = %d\n", distance);
            if (distance <= 3)
            {
                monster_blood--;
                // printf("attack1 sucess, monster_blood last = %d\n", monster_blood);
            }
        }
        if (strcmp(token, defend) == 0)
        {
            legal_cmd++;
            // printf("defend and back1\n");
            distance++;
            defend_flag = true;
            // printf("current distance = %d\n", distance);
        }

        // todo : 判斷跟怪物距離是否為0
        if (distance == 0)
        {
            printf("NO %d\n", monster_blood);
            monster_kill = true;
            break;
        }
        // todo: 判斷怪物還有沒有血量
        if (monster_blood <= 0)
        {
            printf("YES %d\n", legal_cmd);
            break;
        }

        // todo: 判斷此回合怪獸是否攻擊
        if ((cmd_cnt % 10 == 0) && (defend_flag == false))
        {
            //! monster win
            monster_kill = true;
            printf("NO %d\n", monster_blood);
            break;
        }
        defend_flag = false;
        token = strtok(NULL, ",.");
    }

    if ((monster_blood > 0) && (monster_kill == false))
    {
        printf("NO %d\n", monster_blood);
    }
}