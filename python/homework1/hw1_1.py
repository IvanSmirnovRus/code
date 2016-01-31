# coding: utf-8

import sys
import string


def get_coded_letter(letter, shift):
    if letter.islower():
        alphabet = list(string.lowercase)
        index = ord(letter) - ord('a')
    elif letter.isupper():
        alphabet = list(string.uppercase)
        index = ord(letter) - ord('A')
    else:
        return 0

    shift = shift % len(alphabet)

    while shift > 0:
        shift -= 1
        if index == len(alphabet) - 1:
            index = 0
        else:
            index += 1
    return chr(ord(alphabet[0]) + index)

shift, text = sys.stdin.readlines()

coded_stroka = []
for letter in text:
    coded_letter = get_coded_letter(letter, int(shift))
    if coded_letter:
        coded_stroka.append(coded_letter)
    else:
        coded_stroka.append(letter)
print "".join(coded_stroka)
