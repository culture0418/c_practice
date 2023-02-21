#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // todo : malloc 要空間 (未初始化)
    void *ptr = malloc(sizeof(int) * 4);

    // todo : calloc 要空間 (初始化為0)
    void *ptr2 = calloc(sizeof(int), 4);

    // todo : 釋放記憶體
    free(ptr);
    free(ptr2);
}