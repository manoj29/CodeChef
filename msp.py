import sys

def main():
    N = int(raw_input())
    for i in range(N):
        size = int(raw_input())
        v1 = map(int, raw_input().split())
        v2 = map(int, raw_input().split())
        sys.stdout.write("Case #" + str(i+1) + ": ")
        sorted_v1 = sorted(v1)
        sorted_v2 = sorted(v2)
        result = 0
        for i in range(size):
            result += sorted_v1[i]*sorted_v2[size-(i+1)]
        print result
    return
if __name__ == "__main__":
    main()
