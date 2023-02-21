#include <stdio.h>
void fraction_adder(int a_numerator, int a_denominator, int b_numerator,
                    int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);
int main()
{
    int a_numerator, a_denominator, b_numerator, b_denominator;
    scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
    int c_numerator, c_denominator;
    fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
                   &c_denominator);
    printf("%d/%d\n", c_numerator, c_denominator);
}

void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr)
{
    int gcd;
    *c_numerator_ptr = a_numerator * b_denominator + b_numerator * a_denominator;
    *c_denominator_ptr = a_denominator * b_denominator;
    gcd = GCD(*c_numerator_ptr, *c_denominator_ptr);

    if (gcd > 1)
    {
        *c_numerator_ptr = *c_numerator_ptr / gcd;
        *c_denominator_ptr = *c_denominator_ptr / gcd;
    }
}

int GCD(int dividend, int divisor)
{
    if (divisor == 0)
    {
        return -1;
    }
    int remainder;
    remainder = dividend % divisor;

    if (remainder == 0)
    {
        // printf("gcd = %d\n", divisor);
        return divisor;
    }
    else
    {
        GCD(divisor, remainder);
    }
}