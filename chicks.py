import sys

C = int(raw_input())
for j in range(C):
    N, K, B, T = map(int, raw_input().split())
    X = map(int, raw_input().split())
    V = map(float, raw_input().split())
    num_red = 0
    num_blue = 0
    answer = 0
    for i in reversed(xrange(N)):
        if num_red == K:
            break
        if X[i] + T * V[i] < B:
            num_blue += 1
        else:
            num_red += 1
            answer += num_blue
    sys.stdout.write("Case #" + str(j+1) + ": ")
    if num_red >= K:
        print answer
    else:
        print "IMPOSSIBLE"
