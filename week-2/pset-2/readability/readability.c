#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_letter(string text);
int get_word(string text);
int get_sentence(string text);
void print_grade(int R);

int main(void)
{
  string text = get_string("Text: ");

  int letters = get_letter(text);
  int words = get_word(text);
  int sentences = get_sentence(text);

  float L = (float)letters / (float)words * 100;
  float S = (float)sentences / (float)words * 100;
  int R = 0.0588 * L - 0.296 * S - 15.8;

  print_grade(R);
}

int get_letter(string text)
{
  int count = 0;

  for (int i = 0, N = strlen(text); i < N; i++)
  {
    char letter = tolower(text[i]);

    if (letter >= 'a' && letter <= 'z')
    {
      count++;
    }
  }

  return count;
}

int get_word(string text)
{
  int count = 1;

  for (int i = 0, N = strlen(text); i < N; i++)
  {
    char letter = text[i];

    if (letter == ' ')
    {
      count++;
    }
  }

  return count;
}

int get_sentence(string text)
{
  int count = 0;

  for (int i = 0, N = strlen(text); i < N; i++)
  {
    char letter = text[i];

    if (letter == '.' || letter == '!' || letter == '?')
    {
      count++;
    }
  }

  return count;
}

void print_grade(int R)
{
  if (R >= 16)
  {
    printf("Grade 16+\n");
  }
  else if (R < 1)
  {
    printf("Before Grade 1\n");
  }
  else
  {
    printf("Grade %i\n", R);
  }
}