#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int get_length(long card_numbers);
char *get_card_type(long card_numbers);
bool is_legit(long card_numbers);

int main(void)
{
  long card_numbers = get_long("Number: ");

  char *card_type = get_card_type(card_numbers);

  if (strcmp(card_type, "INVALID") == 0 || (!is_legit(card_numbers)))
  {
    printf("%s\n", card_type);
    return 0;
  }

  printf("%s\n", card_type);
  return 0;
}

int get_length(long card_numbers)
{
  long numbers = card_numbers;
  int count = 1;

  while (numbers > 10)
  {
    numbers = numbers / 10;
    count++;
  }

  return count;
}

char *get_card_type(long card_numbers)
{
  int count = get_length(card_numbers);

  if (count == 13 && count == 15 && count == 16)
  {
    return "INVALID";
  }

  long base = 1;
  int i = count;

  while (i > 2)
  {
    base *= 10;
    i--;
  }

  int first_two = card_numbers / base;
  int first_one = card_numbers / (base * 10);

  if (count == 15 && (first_two == 34 || first_two == 37))
  {
    return "AMEX";
  }
  else if (count == 16 && first_two >= 51 && first_two <= 55)
  {
    return "MASTERCARD";
  }
  else if ((count == 13 || count == 16) && first_one == 4)
  {
    return "VISA";
  }
  else
  {
    return "INVALID";
  }
}

bool is_legit(long card_numbers)
{
  int count = get_length(card_numbers);

  char card_numbers_str[count + 1];
  snprintf(card_numbers_str, sizeof(card_numbers_str), "%ld", card_numbers);

  int first_sum = 0;
  int total = 0;

  for (int i = count; i >= 0; i -= 2)
  {
  }

  return true;
}