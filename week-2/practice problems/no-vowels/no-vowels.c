// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
      printf("Usage: ./no-vowels word\n");
      return 1;
    }

    string word = argv[1];

    string R = replace(word);

    printf("%s", R);
}

string replace(string word)
{
  string R = word;

  for (int i = 0, N = strlen(word); i < N ; i++)
  {
    switch (word[i])
    {
    case 'a':
      R[i] = '6';
      break;
    case 'e':
      R[i] = '3';
      break;
    case 'i':
      R[i] = '1';
      break;
    case 'o':
      R[i] = '0';
      break;
    default:
      R[i] = word[i];
      break;
    }
  }

  return R;
}