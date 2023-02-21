#include <stdio.h>
#include <stdbool.h>

int main()
{
    char ch;
    char alpha;
    int credit = 0;
    int credit_sum = 0;
    float grade = 0;
    float credit_grade_sum = 0;
    bool alpha_flag = false;

    do
    {
        ch = getchar();
        // printf("%c\n", ch);
        if (('0' <= ch) && (ch <= '9'))
        {
            if (alpha_flag == false)
            {
                // printf("get a number!!!\n");
                credit = ch - '0';
                credit_sum += credit;
            }
            else
            {
                // printf("calculating last one grade.....\n");
                switch (alpha)
                {
                case 'A':
                    grade = 4.0;
                    break;
                case 'B':
                    grade = 3.0;
                    break;
                case 'C':
                    grade = 2.0;
                    break;
                case 'F':
                    grade = 0;
                    break;
                default:
                    break;
                }
                credit_grade_sum += credit * grade;
                // printf("cred_grade_sum = %f\n", credit_grade_sum);
                credit = ch - '0';
                credit_sum += credit;
                alpha_flag = false;
            }
        }
        else if (('A' <= ch) && (ch <= 'F'))
        {
            alpha_flag = true;
            alpha = ch;
            // printf("alpha = %c\n", alpha);
        }
        else if ((ch == ',') || (ch == '\n'))
        {
            // printf("get a ','... calculating.....\n");
            if (alpha_flag == true)
            {
                switch (alpha)
                {
                case 'A':
                    grade = 4.0;
                    break;
                case 'B':
                    grade = 3.0;
                    break;
                case 'C':
                    grade = 2.0;
                    break;
                case 'F':
                    grade = 0;
                    break;
                default:
                    break;
                }
                credit_grade_sum += credit * grade;
                // printf("cred_grade_sum = %f\n", credit_grade_sum);
                alpha_flag = false;
            }
        }

        else // input + or -
        {
            // printf("get a sign, calculating.....\n");
            switch (alpha)
            {
            case 'A':
                if (ch == '+')
                    grade = 4.3;
                else
                    grade = 3.7;
                break;
            case 'B':
                if (ch == '+')
                    grade = 3.3;
                else
                    grade = 2.7;
                break;
            case 'C':
                if (ch == '+')
                    grade = 2.3;
                else
                    grade = 1.7;
                break;
            default:
                break;
            }
            credit_grade_sum += credit * grade;
            // printf("cred_grade_sum = %f\n", credit_grade_sum);
            alpha_flag = false;
        }

    } while (ch != '\n');
    printf("%.2f", (credit_grade_sum / credit_sum));
}
