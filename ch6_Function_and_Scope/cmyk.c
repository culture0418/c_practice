#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]);
void print_M(unsigned int mask[][MAX_SIZE]);
void print_Y(unsigned int mask[][MAX_SIZE]);
void print_K(unsigned int mask[][MAX_SIZE]);
void CMYK_to_RGB();

int main()
{
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer)
    {
        // Get color mask.
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer])
        {
        case 'C':
            print_C(mask);
            break;
        case 'M':
            print_M(mask);
            break;
        case 'Y':
            print_Y(mask);
            break;
        case 'K':
            print_K(mask);
            break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void print_C(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            image[i][j] = mask[i][j];
            // printf("%d ", image[i][j]);
        }
        // printf("\n");
    }
}

void print_M(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            image[i][j] = (image[i][j] << 8) + mask[i][j];
            // printf("%d ", image[i][j]);
        }
        // printf("\n");
    }
}

void print_Y(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            image[i][j] = (image[i][j] << 8) + mask[i][j];
            // printf("%d ", image[i][j]);
        }
        // printf("\n");
    }
}

void print_K(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            image[i][j] = (image[i][j] << 8) + mask[i][j];
            // printf("%d ", image[i][j]);
        }
        // printf("\n");
    }
}

void CMYK_to_RGB()
{
    long int r = 0;
    long int g = 0;
    long int b = 0;

    int c = 0;
    int m = 0;
    int y = 0;
    int k = 0;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            c = image[i][j] >> 24;
            m = (image[i][j] << 8) >> 24;
            y = (image[i][j] << 16) >> 24;
            k = (image[i][j] << 24) >> 24;

            r = lround(255 * (100 - c) * (100 - k) / 10000.0);
            g = lround(255 * (100 - m) * (100 - k) / 10000.0);
            b = lround(255 * (100 - y) * (100 - k) / 10000.0);

            image[i][j] = (r << 16) + (g << 8) + b;
        }
    }
}
