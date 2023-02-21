#include <stdio.h>
#define LENGTH 10
int main()
{
    char buf1[LENGTH + 1], buf2[LENGTH + 1], buf3[LENGTH + 1], buf4[LENGTH + 1];
    sscanf("123456", "%4s", buf1);           // 只取4個字元
    sscanf("name:carlo", "%[^:]", buf2);     // 取到":"為止
    sscanf("name:carlo", "%*[^:]:%s", buf3); // 忽略":"之前的部分，並取":"之後的部分
    sscanf("123abcDEF", "%[1-9a-z]", buf4);  // 只取數字和小寫字母

    puts(buf1);
    puts(buf2);
    puts(buf3);
    puts(buf4);

    int hour, min, sec, ms;
    sscanf("2018-11-29 13:39:08.838", "%*[^ ] %d:%d:%d.%d", &hour, &min, &sec, &ms);
}