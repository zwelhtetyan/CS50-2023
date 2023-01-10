#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_size(string size_type, int start_size);

int main(void)
{
    // TODO: Prompt for start size
    int start_size = trunc(get_size("start", 9));

    // TODO: Prompt for end size
    int end_size = trunc(get_size("end", start_size));

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    int result = start_size;

    if (start_size == end_size)
    {
        // TODO: Print number of years
        printf("Years: %d", year);
    } else
    {
        do
        {
            result = result + result / 3 - result / 4;

            year++;
        }
        while(result < end_size);

        // TODO: Print number of years
        printf("Years: %d", year);
    }
}

int get_size(string size_type, int start_size)
{
    int size;
    const string question = size_type == "start" ? "Start size: " : "End size: ";
    const int limit = size_type == "start" ?  9 : start_size;

    do
    {
        printf("%s", question);
        scanf("%d", &size);
    }
    while(size < limit );

    return size;
}


