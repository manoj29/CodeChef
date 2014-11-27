import sys

def main():
    t9 = {'a':'2', 'b':'22', 'c':'222', 'd':'3', 'e':'33', 'f':'333',
          'g':'4', 'h':'44', 'i':'444', 'j':'5', 'k':'55', 'l':'555',
          'm':'6', 'n':'66', 'o':'666', 'p':'7', 'q':'77', 'r':'777',
          's':'7777', 't':'8', 'u':'88', 'v':'888', 'w':'9', 'x':'99',
          'y':'999', 'z':'9999', ' ':'0'}
    N = int(raw_input())
    for i in range(N):
        text = raw_input()
        sys.stdout.write("Case #"+ str(i+1) + ": ")
        for i in range(len(text)):
            sys.stdout.write (t9[text[i]])
            if i < len(text)-1:
                cur = t9[text[i]]
                nex = t9[text[i+1]]
                if cur[0]== nex[0]:
                    sys.stdout.write (" ")
            else:
                sys.stdout.write ("\n")
    return

if __name__ == "__main__":
    main()
