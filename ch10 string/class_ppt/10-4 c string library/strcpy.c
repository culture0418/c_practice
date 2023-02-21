#include <stdio.h>
#include <string.h>
#define LENGTH 20
int main()
{
    //! strcpy(str1, str2) 不會檢查 str2 有沒有超出 str1 的大小

    char str1[LENGTH + 1];
    strcpy(str1, "abc");
    puts(str1);

    //! strncpy(str1, str2, sizeof(str1)-1) 比較安全的寫法
    strncpy(str1, "abcd", sizeof(str1) - 1);
    puts(str1);

    return 0;
}