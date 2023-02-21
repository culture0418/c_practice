#include <stdio.h>
#define INT_TYPE 0
#define DOUBLE_TYPE 1

typedef struct
{
    int kind;
    union
    {
        int i;
        double d;
    } u;
} number;

void print(number n);
int main()
{
    //! array 可以同時存 int or double
    number number_array[100];
    number_array[0].u.d = 180.5;
    number_array[0].kind = DOUBLE_TYPE;
    print(number_array[0]);
}

void print(number n)
{
    if (n.kind == INT_TYPE)
        printf("int num = %d\n", n.u.i);
    else
        printf("double num = %lf\n", n.u.d);
}