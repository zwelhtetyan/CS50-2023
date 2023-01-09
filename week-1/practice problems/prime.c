#include <stdio.h>
#include <stdbool.h>

bool prime(int number);

int main(void) {
  int min;
  int max = 100;

  do {
    printf("Enter the minimum number: ");
    scanf("%d", &min);
  } while (min < 1);

  do {
    printf("Enter the maximum number: ");
    scanf("%d", &max);
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