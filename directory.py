def populate(dir_):
    return dir_.split("/")

T = int(raw_input())
for i in range(T):
    N,M = map(int, raw_input().split())
    dirlist = [['']]
    counter = 0
    for j in range(N):
        dirlist.append(populate(raw_input()))
    for j in range(M):
        dir_create = raw_input()
        dir_split = dir_create.split("/")
        dir_strip = dir_split[:]
        for k in range(len(dir_strip)):
            if dir_strip in dirlist:
                break
            else:
                dirlist.append(dir_strip)
                counter +=1
                dir_strip =  dir_strip[:-1]
    print "Case #%d:"%(i+1), counter
