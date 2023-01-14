#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_start_size(void);
int get_end_size(int start_size);

int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_start_size();

    // TODO: Prompt for end size
    int end_size = get_end_size(start_size);

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    int result = start_size;

    if (start_size == end_size)
    {
        // TODO: Print number of years
        printf("Years: %d", year);
    }
    else
    {
        do
        {
            result = result + result / 3 - result / 4;

            year++;
        }
        while (result < end_size);

        // TODO: Print number of years
        printf("Years: %d", year);
    }
}

// get start size
int get_start_size(void)
{
    int size;

    do
    {
        size = get_int("Start size: ");
    }
    while (size < 9);

    return size;
}

// get end size
int get_end_size(int start_size)
{
    int size;

    do
    {
        size = get_int("End size: ");
    }
    while (size < start_size);

    return size;
}