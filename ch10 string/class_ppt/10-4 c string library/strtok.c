#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[80] = " today is sunny day, tomorrow will be sunny day too.";
    char *token;
    token = strtok(sentence, " ,.");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ,.");
    }

    return 0;
}