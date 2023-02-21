#include <stdio.h>
#define LENGTH 15
int main()
{
    char date[LENGTH + 1];

    //! scanf 不能偵測放的 array 是不是超過了
    //! 這裡不用在加 &date 因為 date 會被 compiler 當作 pointer
    // todo scanf 讀的時候會掠過前面的空白，然後再遇到空白時會結束 會自動再 string 尾巴存入 \0
    scanf("%s", date);

    // todo scanf 更安全的用法 規定讀幾個字元
    scanf("%3s", date);
    printf("%s\n", date);

    return 0;
}