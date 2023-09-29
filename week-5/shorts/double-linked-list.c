#include <stdio.h>
#include <stdlib.h>

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

// defining root globally
node *root = NULL;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./double-linked-list 1 2 3 etc...");
        return 1;
    }

    // init double linked lists
    init_nodes(argc, argv);

    node *ptr = root;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
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
