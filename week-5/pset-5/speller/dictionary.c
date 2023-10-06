// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Word count
unsigned int NUMBER_OF_WORD = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char cp_word[LENGTH + 1];
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        cp_word[i] = tolower(word[i]);
    }
    cp_word[n] = '\0';

    int hash_value = hash(cp_word);
    node *current = table[hash_value];

    while (current != NULL)
    {
        if (strcmp(current->word, cp_word) == 0)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int total = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        total += tolower(word[i]) - 'a';
    }

    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *infile = fopen(dictionary, "r");
    if (!infile)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(infile, "%s", word) != EOF)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            unload();
            return false;
        }

        strcpy(new->word, word);
        new->next = NULL;

        int hash_value = hash(word);

        node *current = table[hash_value];
        if (current == NULL)
        {
            table[hash_value] = new;
            NUMBER_OF_WORD++;
        }
        else
        {
            new->next = current;
            table[hash_value] = new;
            NUMBER_OF_WORD++;
        }
    }

    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return NUMBER_OF_WORD;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];

        while (current != NULL)
        {
            node *next = current->next;
            free(current);
            current = next;
        }
    }

    return true;
}
