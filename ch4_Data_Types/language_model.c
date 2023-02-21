#include <stdio.h>

int main()
{
    double Prob[5];
    double Result[5];
    double output = 1;
    for (int i = 0; i < 5; i++)
    {
        scanf("%lf", &Prob[i]);
    }

    // initial
    Result[0] = Prob[0];

    for (int i = 1; i < 5; i++)
    {
        Result[i] = (Prob[i] * Prob[i - 1]) / Result[i - 1];
    }

    for (int i = 0; i < 5; i++)
    {
        output *= Result[i];
    }
    printf("%.15lf", output);
    // printf("%lf", Prob[1]);
}
