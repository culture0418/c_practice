#include <stdio.h>

int main()
{
    int n; // sequence number
    int Seq[n];
    int Prefix[n];
    int p;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Seq[i]);
    }

    // initialize
    // p = Seq[0];
    // Prefix[0] = p;
    Prefix[0] = Seq[0];

    for (int i = 1; i < n; i++)
    {
        Prefix[i] = Prefix[i - 1] + Seq[i];
    }

    for (int i = 0; i < n; i++)
    {
        if ((Prefix[i] % Seq[i]) == 0)
        {
            printf("%d %d\n", Prefix[i], Seq[i]);
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("prefix[%d] = %d ", i, Prefix[i]);
    //     printf("seq[%d] = %d ", i, Seq[i]);
    //     printf("\n");
    // }
}
