#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_YEAR 10

typedef struct _tries
{
    char *university;
    struct _tries *year[NUM_OF_YEAR];
} tries;

int prompt_number = 3;

tries *root = NULL;

// function prototype
void set_null(tries *current);
char *valid_university(char *year);
void destroyer(tries *current);
bool destroy();

int main(void)
{
    root = malloc(sizeof(tries));
    if (root == NULL)
    {
        printf("failed to allocate memory!");
        return 1;
    }

    set_null(root);

    // getting loop_count from users
    int loop_count = get_int("Loop count: ");

    prompt_number = loop_count;

    while (prompt_number > 0)
    {
        char *university_name = get_string("University: ");
        char *year = get_string("Year: ");

        tries *temp = root;

        for (int i = 0, N = strlen(year); i < N; i++)
        {
            int num = year[i];

            if (temp->year[num] == NULL)
            {
                tries *new_node = malloc(sizeof(tries));
                set_null(new_node);

                temp->year[num] = new_node;
            }

            temp = temp->year[num];
        }
        temp->university = university_name;

        prompt_number--;
    }

    prompt_number = loop_count; // resetting prompt number because it has been decreased by first while loop
    while (prompt_number > 0)
    {
        char *year = get_string("Year: ");

        char *university_result = valid_university(year);
        printf("%s\n", university_result);

        prompt_number--;
    }

    if (!destroy())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    return 0;
}

void set_null(tries *current)
{
    current->university = NULL;
    for (int i = 0; i < NUM_OF_YEAR; i++)
    {
        current->year[i] = NULL;
    }
}

char *valid_university(char *year)
{
    tries *temp = root;

    for (int i = 0, N = strlen(year); i < N; i++)
    {
        int num = year[i];
        if (temp->year[num] == NULL)
        {
            return "University not found!";
        }
        temp = temp->year[num];
    }

    return temp->university;
}

bool destroy()
{
    destroyer(root);

    return true;
}

void destroyer(tries *current)
{
    for (int i = 0; i < NUM_OF_YEAR; i++)
    {
        if (current->year[i] != NULL)
        {
            destroyer(current->year[i]);
        }
    }

    free(current);
}