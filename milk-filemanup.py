op = open("input.txt", 'w')
ctr = 1
report = {}
with open("small.in", 'r') as ip:
    cases = int (ip.readline())
    while True:
        if ctr == cases+1:
            break
        op.write("Case #"+str(ctr)+"\n")
        ctr +=1
        op.write(ip.readline())
        skipped_lines = int(ip.readline())
        op.write(str(skipped_lines) + "\n")
        for i in range(skipped_lines):
            op.write(ip.readline())
        op.write ("=============================================="+"\n")
        if skipped_lines <= 10:
            report[ctr-1] = skipped_lines
op.write("Report: ")
op.write(str(report))
op.close()
ip.close()
