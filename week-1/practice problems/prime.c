#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool prime(int number);

int main(void) {
  int min;
  int max;

  do {
    min = get_int("Enter the minimum number: ");
  } while (min < 1);

  do {
    max = get_int("Enter the maximum number: ");
  } while (max <= min);

  for (int i = min; i <= max; i++) {
    if (prime(i)) {
      printf("%d\n", i);
    }
  }
}

bool prime(int number) {
  int isPrime = true;

  if (number < 2) isPrime = false;

  for (int j = 2; j < number; j++) {
    if (number % j == 0) {
      isPrime = false;
      break;
    }
  }

  return isPrime;
}