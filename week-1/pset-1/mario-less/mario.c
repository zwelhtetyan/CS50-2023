#include <cs50.h>
#include <stdio.h>

int get_height(void);
void make_birck(int height);

int main(void)
{
    // get height from user
    int height = get_height();

    // generate bricks
    make_birck(height);
}

int get_height(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

void make_birck(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int z = 0; z < height - i; z++)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}   printf("\n");
    }
}