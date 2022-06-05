# mario.py
from cs50 import get_int


def main():
    height = get_height()
    print_blocks(height)


def print_blocks(height):
    for i in range(height):
        print(" " * (height - 1 - i) + "#" * (i + 1), end='')
        print("  ", end='')
        print("#" * (i + 1))


def get_height():
    while True:
        height = get_int("Height: ")
        if 1 <= height <= 8:
            break
    return height


main()