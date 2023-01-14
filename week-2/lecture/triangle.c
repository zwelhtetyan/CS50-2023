#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

int get_length(void);
bool is_triangle(int x,int y,int z);

int main(void)
{
  int x = get_length();
  int y = get_length();
  int z = get_length();

  bool isTriangle = is_triangle(x, y, z);

  printf("%s\n", isTriangle ? "true" : "false");
}

int get_length(void)
{
  int length = 0;

  do
  {
    length = get_int("Length: ");
  } while (length < 0);

  return length;
}

bool is_triangle(int x,int y,int z)
{
  bool isTriangle = false;

  if (x + y > z || x + z > y || y + z > x)
  {
    isTriangle = true;
  }

  return isTriangle;
}