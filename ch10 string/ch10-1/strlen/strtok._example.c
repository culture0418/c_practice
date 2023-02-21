// todo : 字串切割範例 可以有兩個符號
// todo : strtok(NULL, "| ,")

#include <stdio.h>

int main()
{
    // 首先定义一个字符串
    char str[] = "asdfg| das,da asda";
    char *sub = strtok(str, "| ,");
    while (sub)
    {
        printf("%s\n", sub);
        sub = strtok(NULL, "| ,");
    }
    return 0;
}
