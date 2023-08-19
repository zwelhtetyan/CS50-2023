#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "write.h"

typedef struct my_node
{
    int number;
    struct my_node *next;
} node;

int main(int argc, char *argv[])
{
    char *flags = "peod";

    char flag = getopt(argc, argv, flags);
    if (flag == '?')
    {
        printf("Invalid flag.\n");
        return 1;
    }

    if (getopt(argc, argv, flags) != -1)
    {
        printf("Only one flag allowed.\n");
        return 2;
    }

    if (argc != optind + 2 || argc == 3 && flag == -1)
    {
        printf("Usage: ./number [flag] min max.\n");
        return 3;
    }

    int min = atoi(argv[argc - 2]);
    int max = atoi(argv[argc - 1]);

    write_number(min, max);

    // switch (flag)
    // {
    // // prime
    // case 'p':
    //     get_prime();
    //     break;

    // // even
    // case 'e':
    //     get_even();
    //     break;

    // // odd
    // case 'o':
    //     get_odd();
    //     break;

    // // write all
    // case 'd':
    //     get_all();
    //     break;
    // }
}

void write_number(int min, int max)
{
    FILE *file = fopen("numbers.txt", "w");

    for (int num = min; num <= max; num++)
    {
        fprintf(file, "%i\n", num);
    }

    fclose(file);
}