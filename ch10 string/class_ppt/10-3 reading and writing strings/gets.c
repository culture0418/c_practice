#include <stdio.h>
#define LENGTH 10
int main()
{
    //! gets 不能偵測存放的 array 有沒有超過大小
    // todo gets 不會忽略前面的空白 看到換行符號才結束 會在尾端自動加上 \0
    char weather[LENGTH + 1];
    gets(weather);
    puts(weather);
    return 0;
}