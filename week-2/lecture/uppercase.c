#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  string name = get_string("Name: ");

  printf("Output: ");

  for (int i = 0, n = strlen(name); i < n; i++)
  {
    printf("%c", toupper(name[i]));
  }

  printf("\n");
}