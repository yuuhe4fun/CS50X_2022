from cs50 import get_string


def main():
    text = get_string("Text: ")
    letter_num = count_letters(text)
    word_num = len(text.split())
    sentence_num = count_sentences(text)

    # L is the average number of letters per 100 words in the text
    L = letter_num / (word_num / 100)
    # S is the average number of sentences per 100 words in the text
    S = sentence_num / (word_num / 100)
    # index = 0.0588 * L - 0.296 * S - 15.8
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1\n")
    elif index >= 16:
        print("Grade 16+\n")
    else:
        print("Grade", index)


def count_letters(text):
    letter_num = 0
    for i in range(len(text)):
        if str.isalpha(text[i]):
            letter_num = letter_num + 1
    return letter_num


def count_sentences(text):
    sentence_num = 0
    for i in range(len(text)):
        if (text[i] == '.') or (text[i] == '!') or (text[i] == '?'):
            sentence_num += 1
    return sentence_num


main()
