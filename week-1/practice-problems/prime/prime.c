#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>

bool check_prime(int number);
int get_min(void);
int get_max(void);

int main(void)
{
  int min = get_min();
  int max = get_max();

  for (int i = min; i <= max; i++)
  {
    if (check_prime(i))
    {
      printf("%i\n", i);
    }
  }
}

int get_min(void)
{
  int min;

  do
  {
    min = get_int("Minimum: ");
  } while (min < 1);

  return min;
}

int get_max(void)
{
  int max;

  do
  {
    max = get_int("Maximum: ");
  } while (max > 100);

  return max;
}

bool check_prime(int number)
{
  bool is_prime = true;

  if (number < 2)
  {
    is_prime = false;
  }

  for (int i = 2; i < number; i++)
  {

    if (number % i == 0)
    {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}