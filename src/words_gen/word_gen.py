import sys
import random
import string


def gen_char():
    char = random.choice(string.ascii_letters)
    return char


def gen_word(min, max):
    word = ''
    length = min + random.randint(0, max - min)

    for i in range(length):
        word += gen_char()

    return word


def save_word(words):
    f = open('words.txt', 'w')

    for word in words:
        f.write(word + '\n')


def main(max_size, min_length, max_length):
    words = []

    for i in range(max_size):
        words.append(gen_word(min_length, max_length))

    save_word(words)


# generate word_count words which  min_length <= length <= max_length
if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("how to use: python3 word_gen.py words_count min_length max_length")
        exit()
    else:
        word_count = int(sys.argv[1])
        min_len = int(sys.argv[2])
        max_len = int(sys.argv[3])
        main(word_count, min_len, max_len)
