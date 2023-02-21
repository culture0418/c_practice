// Created by USER on 2022/10/13.

#include <stdio.h>

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

typedef int Strength;
typedef int Obedience;

int main()
{
    char op;
    int cnt_inst = 0;

    Strength strength = INIT_STRENGTH;
    Obedience obedience = INIT_OBEDIENCE;

    do
    {
        scanf("%c", &op);
        if (op == '\n')
        {
            break;
        }
        // printf("%c\n", op);
        switch (op)
        {
        case 'e': // eat
            // printf("eat\n");
            strength += STRENGTH_EAT;
            obedience -= OBEDIENCE_EAT;
            break;
        case 't':
            // printf("train\n");
            obedience += OBEDIENCE_TRAIN;
            strength -= STRENGTH_TRAIN;
            break;
        default:
            break;
        }
        // printf("obedience = %d\n", obedience);
        // printf("strength = %d\n", strength);
        // printf("\n");
        if ((obedience >= LEARN_OBEDIENCE) && (strength <= LEARN_STRENGTH))
        {
            cnt_inst += 1;
            // printf("cnt = %d\n", cnt_inst);
            obedience = INIT_OBEDIENCE;
        }
    } while (op != '\n');

    // printf("cnt = %d\n", cnt_inst);
    if (cnt_inst >= 5)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}