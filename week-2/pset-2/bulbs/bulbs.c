#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void showBulbs(int number);

int main(void)
{
    const string text = get_string("Message: ");

    for (int i = 0, N = strlen(text); i < N; i++)
    {
        showBulbs(text[i]);
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}


void showBulbs(int number)
{
    int num = number;

    int binary[BITS_IN_BYTE];

    int i;

    for (i = 0; i < 8; i++) {
        binary[i] = num % 2;
        num /= 2;
    }

    for (i = 7; i >= 0; i--) {
        print_bulb(binary[i]);
    }

    printf("\n");
}
