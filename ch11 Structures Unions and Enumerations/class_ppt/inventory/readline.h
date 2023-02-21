#ifndef READLINE_H
#define READLINE_H

#define NAME_LEN 25
#define MAX_PARTS 100

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int read_line(char str[], int n);

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

#endif