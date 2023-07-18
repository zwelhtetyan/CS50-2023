#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  string key = argv[1];
  int key_length = strlen(key);

  if (key_length != 26)
  {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  for (int i = 0; i < key_length; i++)
  {
    if (isdigit(key[i]) || !isalpha(key[i]))
    {
      printf("Key must only contain alphabetic characters.\n");
      return 1;
    }
    else
    {
      for (int j = 0; j < key_length; j++)
      {
        if (i != j && tolower(key[j]) == tolower(key[i]))
        {
          printf("Key must not contain repeated characters.\n");
          return 1;
        }
      }
    }
  }

  const string plaintext = get_string("plaintext: ");

  printf("ciphertext: ");

  for (int i = 0, N = strlen(plaintext); i < N; i++)
  {
    char letter = plaintext[i];

    if (letter >= 'A' && letter <= 'Z')
    {
      printf("%c", toupper(key[letter - 'A']));
    }
    else if (letter >= 'a' && letter <= 'z')
    {
      printf("%c", tolower(key[letter - 'a']));
    }
    else
    {
      printf("%c", letter);
    }
  }

  printf("\n");
}