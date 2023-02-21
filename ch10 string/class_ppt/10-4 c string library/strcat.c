#include <stdio.h>
#include <string.h>
#define LENGTH 10
int main()
{
    char str1[LENGTH + 1];
    char str2[LENGTH + 1];

    strncpy(str1, "abc", sizeof(str1) - 1);
    strncpy(str2, "def", sizeof(str2) - 1);

    // todo strcat 會把 str2 接再 str1 後面，然後 return str1
    //! strcat 不能檢查 str2接到 str1 後面後有沒有超過 str1 大小
    strcat(str1, str2);
    puts(str1);
    puts(str2);

    return 0;
}