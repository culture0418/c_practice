#include <stdio.h>
#include <ctype.h>

int State_Transition(int, char);
char State_OP(int, char);

int main()
{
    int names_num; // name numbers
    int state;     // state0: toupper; state1:tolower
    char ch;
    char ch_cp;
    scanf("%d", &names_num);

    // initialize
    state = 0;
    ch = getchar(); // 吃掉\n

    do
    {
        ch = getchar();
        ch_cp = State_OP(state, ch);
        state = State_Transition(state, ch);
        if ((ch_cp == '.') || (ch_cp == ';') || (ch_cp == ','))
        {
            names_num = names_num - 1;
            printf("\n");
        }
        else
        {
            printf("%c", ch_cp);
        }
    } while (names_num > 0);
}

int State_Transition(int current_state, char ch)
{
    int next_state;
    switch (current_state)
    {
    case 0:
        if (('A' <= ch) && (ch <= 'z'))
        {
            next_state = 1;
        }
        break;
    case 1:
        if (('A' <= ch) && (ch <= 'z'))
        {
            next_state = 1;
        }
        if ((ch == ' ') || (ch == ';') || (ch == '.') || (ch == ','))
        {
            next_state = 0;
        }
        break;
    default:
        break;
    }
    return next_state;
}

char State_OP(int current_state, char ch)
{
    switch (current_state)
    {
    case 0:
        if (('a' <= ch) && (ch <= 'z'))
        {
            ch = toupper(ch);
        }
        else
        {
            ch = ch;
        }
        break;
    case 1:
        if (('A' <= ch) && (ch <= 'Z'))
        {
            ch = tolower(ch);
        }
        else
        {
            ch = ch;
        }
        break;
    default:
        break;
    }
    return ch;
}