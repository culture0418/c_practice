#include <stdio.h>
#define TITLE_LEN 15
#define AUTHOR_LEN 20
#define DESIGN_LEN 20

struct catalog_item
{
    int stock_number;
    double price;
    int item_type;

    union item
    {
        struct book
        {
            char title[TITLE_LEN + 1];
            char author[AUTHOR_LEN + 1];
            int num_page;
        };

        struct mug
        {
            char design[DESIGN_LEN + 1];
        };

        struct shirt
        {
            char design[DESIGN_LEN + 1];
            int color;
            int size;
        };
    };
};

int main()
{
}