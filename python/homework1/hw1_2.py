import string
import random
import sys
import Queue


def shaffle_text(text):
    shuffled_text = []
    result = []
    for line in text.split('\n'):
        shuffled_line = []
        for word in line.strip().split(' '):
            letters = [symbol for symbol in word
                       if symbol not in string.punctuation]
            if len(letters) > 3:
                middle_word = letters[1:-1]
                random.shuffle(middle_word)
                shuffled_word = letters[0] + ''.join(middle_word) + letters[-1]
            else:
                shuffled_word = ''.join(letters)
            queue = Queue.Queue()
            for letter in shuffled_word:
                queue.put(letter)
            result_word = [symbol if symbol in string.punctuation
                           else queue.get()
                           for symbol in word]
            shuffled_line.append(''.join(result_word))
        shuffled_text.append(' '.join(shuffled_line))
        result.append(' '.join(shuffled_line))
    return '\n'.join(result)

if __name__ == '__main__':
    text = sys.stdin.read()
    print shaffle_text(text)
