#include <stdio.h>
#include <math.h>

int RPS_Game(int left, int right);
int rps_win(int player1, int player2);

static int total_round;
static int game = 0;
static int people;
static int current_round = 1;
static char player_rps[1024]; //! 從 1 開始
static char big_small[1024];  //! 從 1 開始

int main()
{
    scanf("%d", &people);
    total_round = log2(people);
    // printf("total round = %d\n", total_round);
    for (int i = 1; i <= people; i++)
    {
        scanf(" %c", &player_rps[i]);
    }

    for (int i = 1; i <= total_round; i++)
    {
        scanf(" %c", &big_small[i]);
    }

    printf("%d", RPS_Game(1, people));
}

int RPS_Game(int left, int right)
{
    int left_win;
    int right_win;
    if (left + 1 == right)
    {
        current_round = 1;
        return rps_win(left, right);
    }
    if (left < right)
    {
        int mid = (left + right - 1) / 2;

        left_win = RPS_Game(left, mid);
        // printf("left win = %d\n", left_win);
        // printf("\n");
        right_win = RPS_Game(mid + 1, right);
        // printf("\n");
        // printf("right win = %d\n", right_win);
        current_round++;

        return rps_win(left_win, right_win);
    }
}

int rps_win(int player1, int player2)
{
    int win_player;
    game++;
    // printf("game = %d\n", game);
    // printf("current round = %d\n", current_round);

    char player1_rps = player_rps[player1];
    char player2_rps = player_rps[player2];
    // printf("player%d : %c  player%d : %c\n", player1, player1_rps, player2, player2_rps);

    if (player1_rps == player2_rps)
    { //!平手看數字大小
        // printf("equal\n");
        char b_or_s = big_small[current_round];
        // printf("big or small : %c\n", b_or_s);
        switch (b_or_s)
        {
        case 'b':
            win_player = player2;
            break;

        case 's':
            win_player = player1;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (player1_rps)
        {
        case 'r':
            if (player2_rps == 'p')
            {
                win_player = player2;
            }
            else
            {
                win_player = player1;
            }
            break;
        case 'p':
            if (player2_rps == 'r')
            {
                win_player = player1;
            }
            else
            {
                win_player = player2;
            }
            break;
        case 's':
            if (player2_rps == 'r')
            {
                win_player = player2;
            }
            else
            {
                win_player = player1;
            }
            break;
        default:
            break;
        }
    }
    // printf("last people = %d\n", people - 1);
    people = people - 1;
    // if (game == people)
    // {
    //     game = 0;
    //     current_round++;
    // }
    // printf("current round = %d\n", current_round);

    return win_player;
}