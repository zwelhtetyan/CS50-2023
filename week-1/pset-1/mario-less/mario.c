#include <cs50.h>
#include <stdio.h>

int get_mario_size();
void generate_brick(int size);

int main(void)
{
  // get size of brick
  const int size = get_mario_size();

  // generate brick
  generate_brick(size);
}

int get_mario_size()
{
  int size;

  do
  {
    size = get_int("Height: ");
  } while (size < 1 || size > 8);

  return size;
}

void generate_brick(int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int z = 1; z < size - i; z++)
    {
      printf(" ");
    }

    for (int j = 0; j <= i; j++)
    {
      printf("#");
    }

    printf("\n");
  }
}