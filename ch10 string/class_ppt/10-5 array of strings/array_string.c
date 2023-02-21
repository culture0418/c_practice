#include <stdio.h>

int main(int argc, char *argv[])
{
    //! row num 可以被省略，但 col num 一定要有
    // todo 宣告一個 2d array 存放 string
    char planets[][8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

    // todo 宣告一個 array 裡面的 element 是 pointers to strings
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

    return 0;
}