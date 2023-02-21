#include <stdio.h>
#include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main()
{
    char password1[SIZE];
    char password2[SIZE];

    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);

    // Check Password
    // First: Check length
    if (length(password1, password2) == 1)
    {
        printf("Length does not match the requirements");
    }
    else
    {
        // Second: Check for consistency
        if (compare(password1, password2) == 1)
        {
            printf("Not the same password");
        }
        else
        {
            // Third: Check for compliance
            if (content(password1) == 1)
            {
                printf("Do not satisfy the conditions");
            }
            else
            {
                printf("Everything is good");
            }
        }
    }

    return 0;
}

int length(char pwd1[], char pwd2[])
{
    if (strlen(pwd1) < 6 || strlen(pwd1) > 16)
    {
        return 1;
    }
    else if (strlen(pwd2) < 6 || strlen(pwd2) > 16)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int compare(char pwd1[], char pwd2[])
{
    if (strcmp(pwd1, pwd2) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int content(char pwd1[])
{
    int big_letter_flag = 0;
    int little_letter_flag = 0;
    int num_flag = 0;
    char *ch_ptr = pwd1;

    for (; *ch_ptr != '\0'; ch_ptr++)
    {
        if (('0' <= *ch_ptr) && (*ch_ptr <= '9'))
        { // digits
            num_flag++;
        }
        else if (('A' <= *ch_ptr) && (*ch_ptr <= 'Z'))
        { // big_letter
            big_letter_flag++;
        }
        else if (('a' <= *ch_ptr) && (*ch_ptr <= 'z'))
        {
            little_letter_flag++;
        }
    }
    if ((num_flag != 0) && (big_letter_flag != 0) && (little_letter_flag != 0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}