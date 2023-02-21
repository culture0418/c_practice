#include <stdio.h>
union u
{
    int i;
    double d;
};

int main()
{
    //! union initialize
    //! 只有一個 member 可以被 initialize，但不一定要是第一個
    union u u1 = {10};
    union u u2 = {.d = 108.5};
}