#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int calc_letters(string text);
int calc_words(string text);
int calc_sentences(string text);

int main(void)
{
  const string text = get_string("Text: ");

  const int letters = calc_letters(text);
  const int words = calc_words(text);
  const int sentences = calc_sentences(text);

  float L = ((float)letters / (float)words) * 100;
  float S = ((float)sentences / (float)words) * 100;

  const float index = 0.0588 * L - 0.296 * S - 15.8;

  const int Grade = round(index);

  // Before Grade 1
  // Grade 3
  // Grade 16+

  if (Grade >= 16)
  {
    printf("Grade 16+\n");
  }
  else if (Grade < 1)
  {
    printf("Before Grade 1\n");
  }
  else
  {
    printf("Grade %i\n", Grade);
  }
}

int calc_letters(string text)
{
  int r = 0;

  for (int i = 0, N = strlen(text);  i < N; i++)
  {
    if (tolower(text[i]) >= 'a' && tolower(text[i]) <= 'z')
    {
      r++;
    }
  }

  return r;
}

int calc_words(string text)
{
  int r = 1;

  for (int i = 0, N = strlen(text);  i < N; i++)
  {
    if (text[i] == ' ')
    {
      r++;
    }
  }

  return r;
}

int calc_sentences(string text)
{
  int r = 0;

  for (int i = 0, N = strlen(text);  i < N; i++)
  {
    if (text[i] == '!' || text[i] == '.' || text[i] == '?')
    {
      r++;
    }
  }

  return r;
}