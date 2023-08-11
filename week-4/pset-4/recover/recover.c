#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Couldn't open the file!\n");
        return 2;
    }

    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    int count = 0;
    FILE *img = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, raw_file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count++);
            img = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
        else if (img != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    fclose(raw_file);
    fclose(img);
}
