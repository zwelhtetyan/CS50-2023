#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
  string name;
  string number;
}
person;

int main(void)
{
  person peoples[2];

  peoples[0].name = "Zwel";
  peoples[0].number = "123";

  peoples[1].name = "Eillie";
  peoples[1].number = "456";

  string name = get_string("Name: ");

  for (int i = 0; i < 2; i++)
  {
    if (strcmp(peoples[i].name, name) == 0)
    {
      printf("Found %s\n", peoples[i].number);
      return 0;
    }
  }

  printf("Not Found\n");
  return 1;
}