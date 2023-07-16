#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void show_bulb(string message);

int main(void)
{
    string message = get_string("Message: ");

    show_bulb(message);
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

void show_bulb(string message)
{
    int array[BITS_IN_BYTE];

    for (int i = 0, N = strlen(message); i < N; i++)
    {
        int number = message[i];

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            int remainder = number % 2;
            array[j] = remainder;
            number /= 2; // number = number / 2
        }

        for (int x = 7; x >= 0; x--)
        {
            print_bulb(array[x]);
        }

        printf("\n");
    }
}
