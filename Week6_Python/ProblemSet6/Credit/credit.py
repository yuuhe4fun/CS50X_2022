# credit.py
# from cs50 import get_long


count_digits = 0
check_sum = 0
start_num = 0

# Get the card number
card_num = int(input("Number: "))

# Validate credit card numbers
while card_num != 0:
    # Get the LSB digit
    get_digit = card_num % 10

    # checkSum and otherSum
    if (count_digits % 2) != 0:
        # Multiply every other digit, starting with the number’s second-to-last digit
        multi_digit = get_digit * 2

        # Add those products' digits (not the products themselves) together
        check_sum += (multi_digit % 10 + multi_digit // 10)
    else:
        # Sum of the digits that are not multiplied by 2 (starting from the LSB)
        check_sum += get_digit

    # Get the start number
    if (card_num // 100) == 0 and (start_num == 0):
        start_num = card_num

    # Eliminate the last digit from the card number and then increment the count
    card_num = card_num // 10
    count_digits = count_digits + 1

# Get the LSB digit of the checkSum
check_sum %= 10

# Check the condition for each card then print
visa_digits = (count_digits == 13) or (count_digits == 16)

amex_startNum = (start_num == 34) or (start_num == 37)

mastercard_start_num = start_num == 51 or start_num == 52 or start_num == 53 or start_num == 54 or start_num == 55

if check_sum == 0 and count_digits == 15 and amex_startNum:
    print("AMEX\n")
elif check_sum == 0 and (start_num // 10 == 4) and visa_digits:
    print("VISA\n")
elif check_sum == 0 and count_digits == 16 and mastercard_start_num:
    print("MASTERCARD\n")
else:
    print("INVALID\n")
