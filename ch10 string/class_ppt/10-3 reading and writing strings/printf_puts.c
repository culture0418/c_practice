#include <stdio.h>

int main()
{
    // todo printf 會逐一把 string 裡面的字元印出來直到遇到\0
    char str[] = "Are we going having fun yet?";
    printf("%s\n", str);

    // todo 指印出部分字元 : %.ps
    printf("%.5s\n", str);

    // todo 前面預留空格
    //! ask TA
    printf("%3s\n", str);

    // todo puts 會印出整個字串 然後會自動換行
    char str2[] = "happy day";
    puts(str2);

    return 0;
}