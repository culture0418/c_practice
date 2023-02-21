//! wrong 20/100 fixme

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);
int length_check(char *word);
int letter_check(char *word);

int main()
{
    char homework[MAX_LEN + 1];

    // Get the homework content.
    fgets(homework, MAX_LEN, stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}

void recovery(char *homework)
{
    // todo : 宣告 char array 用來儲存正確的答案
    char hw_cpy[MAX_LEN + 1];
    char temp_word[100];
    char white_space[2] = " ";
    strcpy(hw_cpy, homework);

    // todo: 切割字串
    char *token = strtok(hw_cpy, " \n");
    int length_flag;
    int letter_flag;
    int first_time_flag = 1;
    int str_cpy_flag = 0;

    while (token != NULL)
    {
        // todo : 印出token檢查有沒有切對
        // puts(token);

        // todo : check length
        length_flag = length_check(token);
        // printf("length flag = %d\n", length_flag);
        letter_flag = letter_check(token);
        // printf("letter flag = %d\n", letter_flag);

        if ((length_flag == 1) && (letter_flag == 1))
        {
            // printf("legal word\n");
            if ((first_time_flag == 1) || (str_cpy_flag == 0))
            {
                strcpy(homework, token);
                str_cpy_flag++;
            }
            else
            {
                strcat(homework, white_space);
                strcat(homework, token);
            }
        }
        token = strtok(NULL, " \n");
        first_time_flag++;
    }
}

int length_check(char *word) // todo 檢查長度和不合格
{
    if ((strlen(word) > 21) || (strlen(word) < 1))
    { //! length 不合格
        return 0;
    }
    else
    {
        return 1;
    }
}

int letter_check(char *word) // todo: 檢查內文是否都是英文
{
    int flag_array[100] = {0}; // todo: 1 代表是英文字母 ; 2 是正常標點符號 ; -1 是不正常輸出
    int index = 0;
    int punctuation_flag = 0;
    int first_letter_flag = 0;

    for (; *word != '\0'; word++)
    {
        first_letter_flag++;
        if ((*word >= 'A') && (*word <= 'z')) //! 是英文字母
        {
            if (first_letter_flag != 1)
            { //! 不是第一個字母
                // printf("letter = %c\n", *word);
                if (flag_array[index - 1] != 1)
                { //! 檢查字母前面不可以有標點符號
                    // printf("punctuation before letter\n");
                    return 0;
                }
                flag_array[index] = 1;
            }
            else //! 不是第一個字母
            {
                // printf("letter = %c\n", *word);
                flag_array[index] = 1;
            }
        }
        else //! 不是英文字母，檢查是否為正常標點符號
        {
            if (flag_array[index - 1] == 1) //! 前一個是英文字母
            {
                if ((*word == '.') || (*word == ',') || (*word == '!') || (*word == '?'))
                {
                    // printf("punctuation = %c\n", *word);
                    flag_array[index] == 2;
                    punctuation_flag = 1;
                }
                else
                {
                    // printf("wrong word = %c\n", *word);
                    flag_array[index] == -1;
                    return 0; //! return 0 代表此字組是來自貓貓
                }
            }
            else
            { //! 不正常輸入
                // printf("first is punctuation\n");
                return 0;
            }
        }
        index++;
    }
    return 1; //! return 1 代表此自組是來自人類
}