#include <cs50.h>
#include <stdio.h>

int get_mario_size();
void generate_bricks(int size);

int main(void)
{
  int size = get_mario_size();

  generate_bricks(size);
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

void generate_bricks(int size)
{
  for (int i = 1; i <= size; i++)
  {
    for (int j = 1; j <= size - i; j++)
    {
      printf(" ");
    }

    for (int z = 0; z < i; z++)
    {
      printf("#");
    }

    printf("  ");

    for (int x = 0; x < i; x++)
    {
      printf("#");
    }

    printf("\n");
  }
}