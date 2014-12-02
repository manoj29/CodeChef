import sys

list_of_words = []

def parse_message(message):
    ambiguous = False
    word = []
    word_list = []
    for i in range(len(message)):
        if message[i] == "(":
            ambiguous = True
        elif message[i] == ")":
            ambiguous = False
        else:
            word.append(message[i])
        if not ambiguous:
            word_list.append(word)
            word = []
    return word_list

def solve(message, length, i, D):
    count = 0
    sys.stdout.write("Case #" + str(i+1) + ": ")
    possible_words = parse_message(message)
    for i in range(D):
        for j in range(length):
            unmatched = False
            choices = possible_words[j]
            letter = list_of_words[i][j]
            if letter not in choices:
                unmatched = True
                break
        if not unmatched:
            count+=1
    print count


def main():
    ip = map(int, raw_input().split())
    L = ip[0]; D = ip[1]; N = ip[2]
    for i in range(D):
        list_of_words.append(raw_input())
    for i in range(N):
        solve(raw_input(), L, i, D)

if __name__ == "__main__":
    main()
