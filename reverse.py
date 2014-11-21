import sys
def main():
    N = int(raw_input())
    for i in range(N):
        sys.stdout.write("Case #" + str(i+1) + ": ")
        sentence = map(str, raw_input().split());
        for words in reversed(sentence):
            sys.stdout.write(words + " ")
        sys.stdout.write("\n")
    return

if __name__ == "__main__":
    main()
