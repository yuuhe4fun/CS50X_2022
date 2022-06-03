#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkArgument(int argc, string argv[]);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure the program is one command-line argument
    int getInput = checkArgument(argc, argv);
    if (getInput)
    {
        return getInput;
    }
    else
    {
        string plainText = get_string("plaintext: ");
        int key = atoi(argv[1]);
        for (int i = 0; i < strlen(plainText); ++i)
        {
            plainText[i] = rotate(plainText[i], key);
        }
        printf("ciphertext: %s\n", plainText);
    }
}

int checkArgument(int argc, string argv[])
{
    if (argc > 2 || argc <= 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); ++i)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}

char rotate(char c, int n)
{
    char ci;
    if (isalpha(c))
    {
        ci = c + n % 26;
        bool testRotation = islower(ci) || isupper(ci);
        if (!testRotation)
        {
            ci -= 26;
        }
    }
    else
    {
        ci = c;
    }

    return ci;
}