#include <cs50.h>
#include <stdio.h>

float average(int length, int array[]);

int N = 3;

int main(void)
{
  int scores[N];

  for (int i = 0; i < N; i++)
  {
    scores[i] = get_int("Score: ");
  }

  printf("Average: %f\n", average(N, scores));

}

float average(int length, int array[])
{
  int total = 0;

  for (int i = 0; i < length; i++)
  {
    total += array[i];
  }

  return total / (float) (length);
}