#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// int main(void)
// {
//   int n = 50;
//   int *p = &n;

//   printf("%i\n", *p);
// }

int main(void)
{
  char *s = get_string("String: ");
  if (s == NULL)
  {
    return 1;
  }

  char *t = malloc(strlen(s) + 1);
  if (t == NULL)
  {
    return 1;
  }

  strcpy(t, s);
  // for (int i = 0, n = strlen(s) + 1; i < n; i++)
  // {
  //   t[i] = s[i];
  // }

  if (strlen(s) > 0)
  {
    t[0] = toupper(s[0]);
  }

  printf("%s\n", s);
  printf("%s\n", t);

  free(t);

  return 0;
}