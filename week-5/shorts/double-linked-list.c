#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// defining node
typedef struct my_node
{
    int number;
    struct my_node *prev;
    struct my_node *next;
} node;

// function prototype
int init_nodes(int argc, char *argv[]);
node *create_next(node *new_node, int next_number);
void printing_out(void);
node *delete_node(int number);
node *find_node(node *current, int number);
bool destroy(void);
void destroyer(node *current);
bool is_valid_delete_number(int argc, char *argv[], int number);

// defining root globally
node *root = NULL;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./double-linked-list 1 2 3 etc...");
        return 1;
    }

    int number_to_delete;

    do
    {
        number_to_delete = get_int("Enter number to Delete: ");
    } while (!is_valid_delete_number(argc, argv, number_to_delete));

    // init double linked lists
    // init_nodes(argc, argv);

    // printing out
    // printing_out();

    // deleting node
    // delete_node(5);

    // printing out again
    // printing_out();

    // if (!destroy())
    // {
    //     printf("Problem freeing memory!\n");
    //     return 1;
    // }

    return 0;
}

int init_nodes(int argc, char *argv[])
{

    for (int i = 1; i < argc; i += 2)
    {
        int number = atoi(argv[i]);

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("memory allocation failed!\n");
            return 1;
        }

        new_node->number = number;
        new_node->prev = NULL;
        new_node->next = NULL;

        new_node->next = root;
        if (i != 1)
        {
            root->prev = new_node;
        }
        root = new_node;

        if ((i + 1) < argc)
        {
            int next_number = atoi(argv[i + 1]);
            node *next_node = create_next(new_node, next_number);
            if (next_node == NULL)
            {
                printf("memory allocation failed!\n");
                return 1;
            }
        }
    }
}

node *create_next(node *new_node, int next_number)
{
    node *next_node = malloc(sizeof(node));
    if (next_node == NULL)
    {
        return next_node;
    }

    next_node->number = next_number;
    next_node->prev = NULL;
    next_node->next = NULL;

    new_node->prev = next_node;
    next_node->next = new_node;

    root = next_node;

    return next_node;
}

node *delete_node(int number)
{
    node *node_to_delete = find_node(root, number);

    // printf("%i\n", node_to_delete->prev->number);
    // printf("%i\n", node_to_delete->next->number);

    node_to_delete->prev->next = node_to_delete->next;
    node_to_delete->next->prev = node_to_delete->prev;

    free(node_to_delete);
}

node *find_node(node *current, int number)
{
    node *tem = NULL;

    if (current == NULL)
    {
        return tem;
    }

    if (current->number == number)
    {
        return current;
    }
    else
    {
        find_node(current->next, number);
    }
}

void printing_out(void)
{
    node *ptr = root;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}

bool is_valid_delete_number(int argc, char *argv[], int number)
{
    for (int i = 1; i < argc; i++)
    {
        if (argv[i] == number)
        {
            return true;
        }
    }

    return false;
}

bool destroy(void)
{
    destroyer(root);

    return true;
}

void destroyer(node *current)
{
    if (current == NULL)
    {
        return;
    }

    destroyer(current->next);

    free(current);
}
