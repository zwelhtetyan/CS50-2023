#include <stdio.h>

int main(void)
{
    FILE *infile = fopen("t.txt", "r");

    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    char txt[5];

    while (fscanf(infile, "%s", txt) == 1) // always return 1 if txt is valid
    {
        printf("%s\n", txt);
    }

    fclose(infile);

    return 0;
}