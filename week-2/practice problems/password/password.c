// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{

    bool contain_upper = false;
    bool contain_lower = false;
    bool contain_number = false;
    bool contain_symbol = false;

    for (int i = 0, N = strlen(password); i < N; i++)
    {
        if (isupper(password[i]))
        {
            contain_upper = true;
        }
        else if (islower(password[i]))
        {
            contain_lower = true;
        }
        else if (isnumber(password[i]))
        {
            contain_number = true;
        }
        else if (password[i] == '$' || password[i] == '#' || password[i] == '!')
        {
            contain_symbol = true;
        }
    }

    bool is_valid = contain_upper && contain_lower && contain_number && contain_symbol;

    return is_valid;
}
