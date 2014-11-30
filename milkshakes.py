import sys

customer_shake = []

def check_for_consensus(consensus_set, customer_no):
    pref = customer_shake[customer_no]
    for key, value in consensus_set.iteritems():
        if (key in pref) and (value == pref[key]):
            return True
    return False

def modify_set(consensus_set, customer_no, M):
    pref = customer_shake[customer_no]
    unmalted = True
    for key,value in pref.iteritems():
        if(value == 1):
            unmalted = False
            consensus_set[key] = 1
            break
    if(unmalted == True):
        return False
    for i in range(M):
        ret = check_for_consensus(consensus_set, i)
        if ret == False:
            return modify_set(consensus_set, i, M)
    return True


def solve(N, M, C):
    consensus_set = {(i+1):0 for i in range(N)}
    modify_ret = True
    for i in range(M):
        ret = check_for_consensus(consensus_set, i)
        if ret == False:
            modify_ret = modify_set(consensus_set, i, M)
    sys.stdout.write("Case #"+str(C+1)+": ")
    if modify_ret == False:
        print "IMPOSSIBLE"
        return
    for keys, values in consensus_set.iteritems():
        sys.stdout.write(str(values)+" ")
    sys.stdout.write("\n")

def format_data(rawinput, pref_nos):
    shake_malted = {}
    for i in range(pref_nos):
        shake_malted[rawinput[2*i]] = rawinput[2*i+1]
    customer_shake.append(shake_malted)

def main():
    C = int(raw_input())
    for i in range(C):
        N = int(raw_input())
        M = int(raw_input())
        del customer_shake[:]
        for j in range(M):
            customer = map(int, raw_input().split())
            T = customer[0]
            pref_str = customer[1:]
            format_data(pref_str, T)
        solve(N, M, i)

if __name__ == "__main__":
    main()
