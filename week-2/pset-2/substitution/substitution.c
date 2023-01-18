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

  const string plaintext = get_string("plaintext: ");

  printf("ciphertext: ");

  for (int i = 0, N = strlen(plaintext); i < N; i++)
  {
    char letter = tolower(plaintext[i]);

    if (letter >= 'A' && letter <= 'Z')
    {
      printf("%c", key[letter - 'A']);
    }
    if (letter >= 'a' && letter <= 'z')
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