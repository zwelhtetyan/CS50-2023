#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
  // Input card number
  long n = get_long("Number: ");
  // Calculate the length
  int i = 0;
  long l = n;
  while (l > 0)
  {
    l = l / 10;
    i++;
  }
  // Check whether length is valid
  if (i != 13 && i != 15 && i != 16)
  {
    printf("INVALID\n");
    return 0;
  }
  // Calculate sum
  int sum1 = 0;
  int sum2 = 0;
  long x = n;
  int total = 0;
  int d1;
  int d2;
  int mod1;
  int mod2;
  do
  {
    // Remove last digit
    mod1 = x % 10;
    x = x / 10;
    sum1 = sum1 + mod1;
    // Remove second last digit
    mod2 = x % 10;
    x = x / 10;
    // 2 times second last digit and add digits to sum2
    mod2 = mod2 * 2;
    d1 = mod2 % 10;
    d2 = mod2 / 10;
    sum2 = sum2 + d1 + d2;
  } while (x > 0);
  total = sum1 + sum2;
  // Checking Luhn Algorithm
  if (total % 10 != 0)
  {
    printf("INVALID\n");
    return 0;
  }
  // Starting digits
  long start = n;
  do
  {
    start = start / 10;
  } while (start > 100);
  // Checking starting digits for the card type
  if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
  {
    printf("MASTERCARD\n");
  }
  else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
  {
    printf("AMEX\n");
  }
  else if (start / 10 == 4)
  {
    printf("VISA\n");
  }
  else
  {
    printf("INVALID\n");
  }
}
