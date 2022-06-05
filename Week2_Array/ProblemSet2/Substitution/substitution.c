#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkArgument(int argc, string argv[]);
char encryptText(char c, string key);

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
        // get the unencrypted plain text
        string plainText = get_string("plaintext: ");

        // encrypt every character one by one
        for (int i = 0; i < strlen(plainText); ++i)
        {
            plainText[i] = encryptText(plainText[i], argv[1]);
        }
        printf("ciphertext: %s\n", plainText);
    }
}


int checkArgument(int argc, string argv[])
{
    if (argc > 2 || argc <= 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check the key length.
    // Key must contain 26 characters.
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        // check alphabetical characters
        for (int i = 0; i < 26; ++i)
        {
            if (!(isalpha(argv[1][i])))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // check whether or not containing each letter exactly once
        // string flag = (26, '0');
        for (int i = 0; i < 26; ++i)
        {
            for (int j = i + 1; j < 26; ++j)
            {
                if (argv[1][i] == argv[1][j])
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

char encryptText(char c, string key)
{
    char encryptC;
    // check whether the plain text character is an upper character
    // or a lower one
    if (isupper(c))
    {
        // check whether the correlated character in key is an upper
        // character or a lower one
        char keyCharacter = key[(int)c - 65];
        if (isupper(keyCharacter))
        {
            // upper character
            encryptC = keyCharacter;
        }
        else
        {
            // lower character
            encryptC = keyCharacter - 32;
        }
    }
    else if (islower(c))
    {
        // check whether the correlated character in key is an upper
        // character or a lower one
        char keyCharacter = key[(int)c - 97];
        if (isupper(keyCharacter))
        {
            // upper character
            encryptC = keyCharacter + 32;
        }
        else
        {
            // lower character
            encryptC = keyCharacter;
        }
    }
    else
    {
        encryptC = c;
    }
    return encryptC;
}