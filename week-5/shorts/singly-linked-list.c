#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// defining structures
typedef struct my_node
{
    int number;
    struct my_node *next;
} node;

// global variable
node *root = NULL;

// function declaration
node *create(int number);
int init_nodes(int argc, char *argv[]);
bool find(node *find_node, int number);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./singly-lined-list 2 3 4 etc...\n");
        return 1;
    }

    // initialize all lists based on argv
    init_nodes(argc, argv);

    // find numbers
    bool exists = find(root, 3);

    printf("%s\n", exists ? "true" : "false");

    while (root != NULL)
    {
        printf("%i\n", root->number);
        root = root->next;
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