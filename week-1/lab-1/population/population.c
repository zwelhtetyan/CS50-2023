#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_start_size(void);
int get_end_size(int start_size);
int calculate_years(int start_size, int end_size);

int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_start_size();

    // TODO: Prompt for end size
    int end_size = get_end_size(start_size);

    // TODO: Calculate number of years until we reach threshold
    int num_of_year = calculate_years(start_size, end_size);

    // TODO: Print number of years
    printf("Years: %i", num_of_year);
}

int get_start_size(void)
{
    int start_size;

    do
    {
        start_size = get_int("Start size: ");
    } while (start_size < 9);

    return start_size;
}

int get_end_size(int start_size)
{
    int end_size;

    do
    {
        end_size = get_int("End size: ");
    } while (end_size < start_size);

    return end_size;
}

int calculate_years(int start_size, int end_size)
{
    int num_of_year = 0;
    int current_size = start_size;

    if (start_size == end_size)
    {
        return 0;
    }

    do
    {
        num_of_year++;
        current_size = current_size + trunc(current_size / 3) - trunc(current_size / 4);
    } while (current_size < end_size);

    return num_of_year;
}