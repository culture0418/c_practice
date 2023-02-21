#include <stdio.h>
#include <string.h>

// todo strcmp 會逐一比對兩個字串裡面的字元 回傳 -1 or 0 or 1

int main()
{
    //! str1 < str2
    char str1[] = "abc";
    char str2[] = "abd";
    printf("%d\n", strcmp(str1, str2));

    //! 大小字母 都比 小寫字母小
    char str3[] = "ABC";
    char str4[] = "abc";
    printf("%d\n", strcmp(str3, str4));

    //! 數字 都底 英文字母小
    char str5[] = "123";
    char str6[] = "a";
    printf("%d\n", strcmp(str5, str6));

    //! 空白 最小
    char str7[] = "";
    char str8[] = "123";
    printf("%d\n", strcmp(str7, str8));

    return 0;
}