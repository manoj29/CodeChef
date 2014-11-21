import sys
def solve(c, l, p, ctr):
  psorted = sorted(p)
  for i in psorted:
    r = c - i;
    if r in p:
        indices1 = [ind for ind,x in enumerate(p) if x == i ]
        indices2 = [ind for ind,x in enumerate(p) if x == r]
        sys.stdout.write("Case #"+str(ctr+1)+": ")
        if len(indices1) == 2:
            print indices1[0]+1, indices1[1]+1
        else:
            if (indices1[0] < indices2[0]):
                print indices1[0]+1, indices2[0]+1
            else:
                print indices2[0]+1, indices1[0]+1
        return

def main():
  N = int(raw_input())
  for i in range(N):
    c = int (raw_input())
    l = int (raw_input())
    p = map(int, raw_input().split())
    solve(c, l, p, i)

if __name__ ==  "__main__":
  main()
