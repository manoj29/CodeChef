import sys

N = int(raw_input())
for i in range(N):
    floors = []
    counter = 0
    T = int(raw_input())
    floors = [map(int, raw_input().split()) for ind in range(T)]
    sys.stdout.write("Case #" + str(i+1) + ": ")
    for j in range(T-1):
        for k in range (j+1, T):
            if (floors[j][0] - floors[k][0]) * (floors[j][1] - floors[k][1]) < 0:
                counter+=1
    sys.stdout.write(str(counter) + "\n")
