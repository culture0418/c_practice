#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int *num_count(char letter);
int main()
{
    char line[BUFFER_LEN];
    char buffer[LINE_LEN][BUFFER_LEN];
    char *arr[LINE_LEN];

    int count = 0; //! count 代表這行內有幾個單字
    while (fgets(line, BUFFER_LEN - 1, stdin) != NULL)
    {
        arr[count] = buffer[count];
        strncpy(buffer[count++], line, BUFFER_LEN - 1);
    }
    convert(arr, count);

    for (int i = 0; i < count; i++)
    {
        printf("%s", arr[i]);
    }
}

void convert(char *arr[], int count)
{
    const char *nums[] = {"0", "0", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char ans_arr[LINE_LEN][BUFFER_LEN];
    int sentence_index = 0;

    for (sentence_index = 0; sentence_index < count; sentence_index++)
    {
        char *token;
        int *num_count_ptr;
        token = strtok(arr[sentence_index], " \n");
        // printf("token = %s\n", token);

        int letter_index = 0;
        while ((token != NULL) && (token != "\n") && (token != " "))
        {
            for (int i = 0; i < strlen(token); i++)
            {
                num_count_ptr = num_count(token[i]);

                // todo : 'd'
                ans_arr[sentence_index][letter_index] = '(';
                ans_arr[sentence_index][letter_index + 1] = (char)('0' + num_count_ptr[0]); // todo: 要記得轉型成 int
                ans_arr[sentence_index][letter_index + 2] = ')';
                ans_arr[sentence_index][letter_index + 3] = (char)('0' + num_count_ptr[1]); // todo : 要記得轉型成 int
                letter_index += 4;
            }

            letter_index++;
            strcat(ans_arr[sentence_index], " ");

            token = strtok(NULL, " \n");
            // printf("token = %s\n", token);
        }
        strcat(ans_arr[sentence_index], "\n");
        arr[sentence_index] = ans_arr[sentence_index];
    }
}

// todo: 助教寫法!!!
// int arr[256];
// arr['a'] = 1;
// arr['b'] = 1;

int *num_count(char letter) // todo: return num and count times
{
    int num_and_count[2] = {0};
    int *num_and_count_ptr = num_and_count;

    switch (letter)
    {
    case 'a':
        num_and_count[0] = 2;
        num_and_count[1] += 1;
        break;
    case 'b':
        num_and_count[0] = 2;
        num_and_count[1] += 2;
        break;
    case 'c':
        num_and_count[0] = 2;
        num_and_count[1] += 3;
        break;
    case 'd':
        num_and_count[0] = 3;
        num_and_count[1] += 1;
        break;
    case 'e':
        num_and_count[0] = 3;
        num_and_count[1] += 2;
        break;
    case 'f':
        num_and_count[0] = 3;
        num_and_count[1] += 3;
        break;
    case 'g':
        num_and_count[0] = 4;
        num_and_count[1] += 1;
        break;
    case 'h':
        num_and_count[0] = 4;
        num_and_count[1] += 2;
        break;
    case 'i':
        num_and_count[0] = 4;
        num_and_count[1] += 3;
        break;
    case 'j':
        num_and_count[0] = 5;
        num_and_count[1] += 1;
        break;
    case 'k':
        num_and_count[0] = 5;
        num_and_count[1] += 2;
        break;
    case 'l':
        num_and_count[0] = 5;
        num_and_count[1] += 3;
        break;
    case 'm':
        num_and_count[0] = 6;
        num_and_count[1] += 1;
        break;
    case 'n':
        num_and_count[0] = 6;
        num_and_count[1] += 2;
        break;
    case 'o':
        num_and_count[0] = 6;
        num_and_count[1] += 3;
        break;
    case 'p':
        num_and_count[0] = 7;
        num_and_count[1] += 1;
        break;
    case 'q':
        num_and_count[0] = 7;
        num_and_count[1] += 2;
        break;
    case 'r':
        num_and_count[0] = 7;
        num_and_count[1] += 3;
        break;
    case 's':
        num_and_count[0] = 7;
        num_and_count[1] += 4;
        break;
    case 't':
        num_and_count[0] = 8;
        num_and_count[1] += 1;
        break;
    case 'u':
        num_and_count[0] = 8;
        num_and_count[1] += 2;
        break;
    case 'v':
        num_and_count[0] = 8;
        num_and_count[1] += 3;
        break;
    case 'w':
        num_and_count[0] = 9;
        num_and_count[1] += 1;
        break;
    case 'x':
        num_and_count[0] = 9;
        num_and_count[1] += 2;
        break;
    case 'y':
        num_and_count[0] = 9;
        num_and_count[1] += 3;
        break;
    case 'z':
        num_and_count[0] = 9;
        num_and_count[1] += 4;
        break;

    default:
        return EXIT_FAILURE;
        break;
    }
    return num_and_count_ptr;
}
