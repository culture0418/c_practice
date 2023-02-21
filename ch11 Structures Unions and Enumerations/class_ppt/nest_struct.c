#include <stdio.h>
#include <string.h>
#define FIRST_NAME_LEN 10
#define LAST_NAME_LEN 15

struct person_name
{
    char first[FIRST_NAME_LEN + 1];
    char middle_initial;
    char last[LAST_NAME_LEN + 1];
};

struct student
{
    struct person_name name;
    int id;
    int age;
    char sex;
};

int main()
{
    struct person_name new_name = {.first = "Fred", .middle_initial = 'c', .last = "Chen"};
    struct student student1;
    strcpy(student1.name.first, "Fred");

    student1.name = new_name;
}