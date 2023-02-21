#include <stdio.h>

enum suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

typedef enum
{
    FALSE,
    TRUE
} bool;

enum dept
{
    research = 20,
    abc = 20
};

typedef struct
{
    enum
    {
        INT_TYPE,
        DOUBLE_TYPE
    } kind;
    union
    {
        int i;
        double d;
    } u;
} number;
