#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

#define SIZE 10
#define NUM_LIMIT 100

typedef struct my_node
{
    bool valid_number;
    struct my_node *children[SIZE];
} node;

node *root;

bool check(char *numbers);
bool unload(void);

int main(int argc, char *argv[])
{
    FILE *text_file = fopen("numbers.txt", "r");
    if (text_file == NULL)
    {
        printf("File reading failed!\n");
        return 1;
    }

    char num[NUM_LIMIT];
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return 1;
    }

    root->valid_number = false;
    for (int i = 0; i < SIZE; i++)
    {
        root->children[i] = NULL;
    }

    while (fscanf(text_file, "%s", num) == 1)
    {
        node *cursor = root;

        for (int i = 0, N = strlen(num); i < N; i++)
        {
            int idx = num[i] - 48; // 48 -> 0, 49 -> 1, ...
            if (cursor->children[idx] == NULL)
            {
                node *new_node = malloc(sizeof(node));
                new_node->valid_number = false;
                for (int i = 0; i < SIZE; i++)
                {
                    new_node->children[idx] = NULL;
                }

                cursor->children[idx] = new_node;
            }

            cursor = cursor->children[idx];
        }

        cursor->valid_number = true;
    }

    if (check(get_string("Check valid number: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found!\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(text_file);
}

bool check(char *numbers)
{
    node *cursor = root;

    for (int i = 0, N = strlen(numbers); i < N; i++)
    {
        int idx = numbers[i] - 48;
        if (cursor->children[idx] == NULL)
        {
            return false;
        }
        cursor = cursor->children[idx];
    }

    return cursor->valid_number;
}

void unloader(node *current)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    free(current);
}

bool unload(void)
{
    unloader(root);

    return true;
}
