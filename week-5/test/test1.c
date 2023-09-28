#include <stdio.h>
#include <stdlib.h>

typedef struct MyNode
{
    int number;
    struct MyNode *next;
} node;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./test1 number\n");
        return 1;
    }

    int limit = atoi(argv[1]);

    node *list = NULL;
    for (int i = 1; i <= limit; i++)
    {
        node *n = malloc(sizeof(node));

        n->number = i;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
