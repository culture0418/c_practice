#include <stdio.h>

int main()
{
    char num[12];
    int digits[12];
    int even_digits_sum, odd_digits_sum, output;

    scanf("%s", &num); // 以 string type 讀取資料
    // 每位數轉換成 int type
    for (int i = 0; i < 12; i++)
    {
        digits[i] = num[11 - i] - '0';
        // printf("%d\n", digits[i]);
    }
    even_digits_sum = digits[0] + digits[2] + digits[4] + digits[6] + digits[8] + digits[10]; // a
    odd_digits_sum = digits[1] + digits[3] + digits[5] + digits[7] + digits[9] + digits[11];  // b

    output = 9 - ((3 * even_digits_sum + odd_digits_sum - 1) % 10);
    printf("%d", output);
    // printf("odd sum = %d\n", odd_digits_sum);
    // printf("even sum = %d\n", even_digits_sum);
}
