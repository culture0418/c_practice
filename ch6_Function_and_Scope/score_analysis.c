#include <stdio.h>

int *Calculate_Interval(int low, int high, int student, int Score[]);

int main()
{
    int student;
    scanf("%d", &student);

    int Score[student];
    for (int i = 0; i < student; i++)
    {
        scanf("%d", &Score[i]);
    }

    int interval_num;
    scanf("%d", &interval_num);

    int Interval_Score[2 * interval_num];
    for (int i = 0; i < 2 * interval_num; i++)
    {
        scanf("%d", &Interval_Score[i]);
    }

    for (int i = 0; i < 2 * interval_num; i += 2)
    {
        int *result_ptr;
        result_ptr = Calculate_Interval(Interval_Score[i], Interval_Score[i + 1], student, Score);
        printf("%d %d %d\n", result_ptr[0], result_ptr[1], result_ptr[2]);
    }
}

int *Calculate_Interval(int low, int high, int student, int Score[])
{
    static int Result[3];

    // initialize
    for (int i = 0; i < 3; i++)
    {
        Result[i] = 0;
    }

    for (int i = 0; i < student; i++)
    {
        if (Score[i] < low)
        {
            Result[0]++;
        }
        else if (Score[i] >= high)
        {
            Result[2]++;
        }
        else
        {
            Result[1]++;
        }
    }
    return Result;
}