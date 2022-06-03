#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    int index;
    // L is the average number of letters per 100 words in the text
    float L;
    // S is the average number of sentences per 100 words in the text
    float S;

    string text;
    text = get_string("Text: ");

    int letterNum, wordNum, sentenceNum;
    letterNum = count_letters(text);
    wordNum = count_words(text);
    sentenceNum = count_sentences(text);

    L = (float) letterNum / wordNum * 100;
    S = (float) sentenceNum / wordNum * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letterNum = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letterNum ++;
        }
    }

    return letterNum;
}

int count_words(string text)
{
    int wordNum = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // if (text[i] == ' ')
        // {
        //     wordNum += 1;
        // }
        if (text[i] == '-' && isalpha(text[i - 1])) {}

        else if (text[i] == 39 && isalpha(text[i - 1])) {}

        else if (!isalpha(text[i]) && isalpha(text[i - 1]))
        {
            wordNum ++;
        }
    }

    return wordNum;
}

int count_sentences(string text)
{
    int sentenceNum = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentenceNum += 1;
        }
    }

    return sentenceNum;
}