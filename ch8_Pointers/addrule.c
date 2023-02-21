#include <stdio.h>
#include <math.h>

int sign(int num);
int exponent(int num, int *num_ide);
void fraction(int num, int *num_ide);
int full_adder_c(int a, int b, int c);
int full_adder_x(int a, int b, int c);
int transfer_to_sign_int(int sum[]);
void print_array(int num1_array[], int num2_array[], int sum_array[]);

int main()
{
    int num1;
    int num2;
    int transfer_ans;
    scanf("%d", &num1);
    scanf("%d", &num2);

    int num1_ide[32];
    int num2_ide[32];
    int sum[32] = {0};

    int *num1_ptr = num1_ide;
    int *num2_ptr = num2_ide;

    exponent(num1, num1_ptr); // todo 決定指數
    exponent(num2, num2_ptr); // todo 決定指數

    for (int i = 9; i <= 32; i++)
    { //! fraction initial
        num1_ide[i] = 0;
        num2_ide[i] = 0;
    }

    fraction(num1, num1_ptr);
    fraction(num2, num2_ptr);

    num1_ide[0] = sign(num1); // todo 判斷正負
    num2_ide[0] = sign(num2); // todo 判斷正負

    int c = 0; //! lsb carry = 0
    for (int i = 31; i >= 0; i--)
    {
        sum[i] = full_adder_x(num1_ide[i], num2_ide[i], c);
        c = full_adder_c(num1_ide[i], num2_ide[i], c);
        // printf("num1[%d] = %d  num2[%d] = %d  c = %d sum[%d] = %d\n", i, num1_ide[i], i, num2_ide[i], c, i, sum[i]);
    }
    transfer_ans = transfer_to_sign_int(sum);
    print_array(num1_ide, num2_ide, sum);
    printf("\n");
    printf("%d + %d = %d\n", num1, num2, transfer_ans);
    return 0;
}

int sign(int num)
{
    if (num > 0)
    {
        // printf("positive\n");
        return 0;
    }
    else
    {
        // printf("negative\n");
        return 1;
    }
}

int exponent(int num, int *num_ide)
{
    if (num < 0)
    {
        num = 0 - num;
    }

    int exp = lround(log2(num));
    int exp_base127 = exp + 127;
    // printf("exp127 = %d\n", exp_base127);

    int array[8];
    int i = 0;
    while (exp_base127 > 0)
    {
        array[i] = exp_base127 % 2;
        exp_base127 = exp_base127 / 2;
        i++;
    }

    num_ide = num_ide + 1; //! exp 從 1 開始填

    for (; i > 0; i--)
    {
        *num_ide = array[i - 1];
        // printf("%d", *num_ide);
        num_ide++;
    }
    // printf("\n");
}

void fraction(int num, int *num_ide)
{
    int array[23];
    int i = 0;
    if (num < 0)
    {
        num = 0 - num;
    }
    int exp = lround(log2(num));

    while (num > 0)
    {
        array[i] = num % 2;
        num = num / 2;
        i++;
    }
    i = i - 2; //! 跳出迴圈 i 多加一次 且最前面的第一位不要

    num_ide = num_ide + 9; //! fraction 從 9開始填
    // printf("i = %d\n", i);
    for (; i >= 0; i--)
    {
        *num_ide = array[i];
        // printf("%d", *num_ide);
        num_ide++;
    }
    // printf("\n);

    num_ide = num_ide + 9;
}

int full_adder_c(int a, int b, int c) // carry
{
    int carry;
    carry = a + b + c; // todo: carry = 0 ~3

    if ((carry / 2) > 0) // todo: carry = 2 or 3 要進位
    {
        carry = 1;
    }
    else // todo: carry = 0 or 1 不進位
    {
        carry = 0;
    }

    return carry;
}

int full_adder_x(int a, int b, int c) // sum
{
    int sum;
    sum = a + b + c;
    if ((sum % 2) == 0)
    {
        sum = 0;
    }
    else
    {
        sum = 1;
    }

    return sum;
}

void print_array(int num1_array[], int num2_array[], int sum_array[])
{
    printf("   ");
    for (int i = 0; i < 32; i++)
    {
        if ((i != 0) && ((i % 8) == 0))
        {
            printf(" ");
            printf("%d", num1_array[i]);
        }
        else
        {
            printf("%d", num1_array[i]);
        }
    }
    printf("\n");
    printf("+) ");
    for (int i = 0; i < 32; i++)
    {
        if ((i != 0) && ((i % 8) == 0))
        {
            printf(" ");
            printf("%d", num2_array[i]);
        }
        else
        {
            printf("%d", num2_array[i]);
        }
    }
    printf("\n");
    printf("---------------------------------------\n");
    printf("   ");
    for (int i = 0; i < 32; i++)
    {
        if ((i != 0) && ((i % 8) == 0))
        {
            printf(" ");
            printf("%d", sum_array[i]);
        }
        else
        {
            printf("%d", sum_array[i]);
        }
    }
}

int transfer_to_sign_int(int sum[])
{
    int neg_flag = 0;
    int two_complement = 0;
    if (sum[0] == 1)
    { //! negative
        // printf("negative\n");
        two_complement = two_complement + (-1) * sum[0] * pow(2, 31);
        for (int i = 1; i <= 31; i++)
        {
            two_complement = two_complement + sum[i] * pow(2, (32 - 1) - i);
        }
    }
    else
    { //! positive
        // printf("positive\n");
        for (int i = 0; i <= 31; i++)
        {
            // printf("exp = %d sum[%d] = %d\n", (31 - i), i, sum[i]);
            two_complement = two_complement + sum[i] * pow(2, (32 - 1) - i);
            // printf("two complement num = %d\n", two_complement);
        }
    }
    return two_complement;
}