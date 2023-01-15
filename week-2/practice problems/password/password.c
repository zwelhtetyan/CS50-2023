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
        printf("Your password is valid!\n");;
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");;
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool isValid = false;

    string check_type[4];
    check_type[0] = "upper";
    check_type[1] = "lower";
    check_type[2] = "number";
    check_type[3] = "special";

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0, N = strlen(password); i < N; i++)
        {
            if (strcmp(check_type[j], "upper") == 0 && password[i] == toupper(password[i]))
            {
                isValid = true;
                break;
            } else if (strcmp(check_type[j], "lower") == 0 && password[i] == tolower(password[i]))
            {
                isValid = true;
                break;
            } else if (strcmp(check_type[j], "number") == 0 && password[i] >= 0)
            {
                isValid = true;
                break;
            } else if (strcmp(check_type[j], "special") == 0 && (password[i] == '!' || password[i] == '$' || password[i] == '#'))
            {
                isValid = true;
                break;
            } else
            {
                isValid = false;
            }
        }
    }

    return isValid;
}
