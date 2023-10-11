#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

bool is_legit(long card_numbers);

int main(void)
{
  printf("%s\n", is_legit(4003600000000014) ? "true" : "false");

  return 0;
}

bool is_legit(long card_numbers)
{
  int count = 16;
  char card_numbers_str[count + 1];

  snprintf(card_numbers_str, sizeof(card_numbers_str), "%ld", card_numbers);

  return false;
}
