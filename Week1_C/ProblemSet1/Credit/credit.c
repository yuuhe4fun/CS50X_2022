#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNum;
    int getDigit;
    int multiDigit;
    int countDigits = 0;
    int checkSum = 0;
    long startNum = 0;
    bool visaDigits, amexStartNum, mastercardStartNum;

    // Get the card number
    cardNum = get_long("Number: ");

    // Validate credit card numbers
    while (cardNum != 0)
    {
        // Get the LSB digit
        getDigit = cardNum % 10;

        // checkSum and otherSum
        if ((countDigits % 2) != 0)
        {
            // Multiply every other digit, starting with the number’s second-to-last digit
            multiDigit = getDigit * 2;

            // Add those products' digits (not the products themselves) together
            checkSum += (multiDigit % 10 + multiDigit / 10);
        }
        else
        {
            // Sum of the digits that weren’t multiplied by 2 (starting from the LSB)
            checkSum += getDigit;
        }

        // Get the start number
        if (cardNum / 100 == 0 && startNum == 0)
        {
            startNum = cardNum;
        }

        // Eliminate the last digit from the card numbem then increment the count
        cardNum = cardNum / 10;
        countDigits++;
    }

    // Get the LSB digit of the checkSum
    checkSum %= 10;

    // Check the condition for each card then print
    visaDigits = countDigits == 13 || countDigits == 16;

    amexStartNum = startNum == 34 || startNum == 37;

    mastercardStartNum = startNum == 51 || startNum == 52 || startNum == 53 ||
                         startNum == 54 || startNum == 55;

    if (checkSum == 0 && countDigits == 15 && amexStartNum)
    {
        printf("AMEX\n");
    }
    else if (checkSum == 0 && startNum / 10 == 4 && visaDigits)
    {
        printf("VISA\n");
    }
    else if (checkSum == 0 && countDigits == 16 && mastercardStartNum)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}