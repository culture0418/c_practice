#include <stdio.h>
#include <string.h>

int count_length(char *p);

int main()
{
    // todo 宣告 string variable 同時 initialize
    char date1[8] = "june 14";

    // todo 宣告長度可以等於初始化的字串的長度，但compiler部會自動在後面補上\0
    char date2[7] = "June 14";

    //! wrong 宣告的長度小於初始化字串的長度
    //! char date3[6] = "june 14";

    // todo 宣告 string variable 時不寫長度 compiler 會自動幫你算
    char date4[] = "June 14";
    printf("string length = %d\n", strlen(date4));

    // todo 宣告 char * as string variable
    //! char *ptr 試紙到一個存放 string literal 的地方 所不能透過 ptr 去修改 string literal
    char *date_ptr = "June 14";
    printf("%s\n", date_ptr);

    // todo 宣告 pointer 指到 char[]
    char *date_p = date1;
    printf("length = %d\n", count_length(date_p));

    return 0;
}

int count_length(char *p)
{
    int count = 0;
    for (; *p != '\0'; p++)
        count++;
    return count;
}