#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// defining structures
typedef struct my_node
{
    int number;
    struct my_node *next;
} node;

// function prototype
node *create(int number);
int init_nodes(int argc, char *argv[]);
bool find(node *find_node, int number);
node *insert(node *new_node, int value);
bool destroy(void);
void destroyer(node *current);

// global variable
node *root = NULL;

int main(int argc, char *argv[])
{
    // base case
    if (argc < 2)
    {
        printf("Usage: ./singly-lined-list 2 3 4 etc...\n");
        return 1;
    }

    // initialize all lists based on argv
    init_nodes(argc, argv);

    // find numbers
    bool exists = find(root, 3);

    // insert new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return 1;
    }

    insert(new_node, 11);

    // printf("%s\n", exists ? "Found number!" : "Number not found!");

    // node *ptr = root;
    // while (ptr != NULL)
    // {
    //     printf("%i\n", ptr->number);
    //     ptr = ptr->next;
    // }

    if (!destroy())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    return 0;
}

node *create(int number)
{
    node *temp = malloc(sizeof(node));
    if (temp == NULL)
    {
        return temp;
    }

    temp->number = number;
    temp->next = NULL;

    temp->next = root;

    root = temp;

    return temp;
}

node *insert(node *new_node, int value)
{
    new_node->number = value;
    new_node->next = NULL;

    new_node->next = root;

    root = new_node;

    return new_node;
}

bool find(node *find_node, int number)
{
    if (find_node == NULL)
    {
        return false;
    }

    if (find_node->number == number)
    {
        return true;
    }
    else
    {
        find(find_node->next, number); // recursion here
    }
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

    node *next = current->next;
    free(current);
    destroyer(next); // recursion here
}

int init_nodes(int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        node *new = create(atoi(argv[i]));

        if (new == NULL)
        {
            return 1;
        }
    }

    return 0;
}