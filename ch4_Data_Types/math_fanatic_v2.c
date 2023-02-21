#include <stdio.h>

int main()
{
    int n;
    long long int num;
    long long int prefix_sum = 0;
    scanf("%d", &n);

    // initial
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &num);
        prefix_sum = num + prefix_sum;
        // printf("prefix_sum = %d\n", prefix_sum);
        if ((prefix_sum % num) == 0)
        {
            printf("%lld %lld\n", prefix_sum, num);
        }
    }
}