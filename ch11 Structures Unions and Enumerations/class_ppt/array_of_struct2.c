#include <stdio.h>
#include <string.h>

struct dialing_code
{
    char *country; //! country name
    int code;      //! country code
};

int main()
{
    const struct dialing_code country_codes[] = {
        {"Japan", 81},
        {"South Korea", 82},
        {"Taiwan", 886}};
}