import sys
n, c = list(map(int, sys.stdin.readline().split()))
arr = list(map(int, sys.stdin.readline().split()))
res ={}
for i in arr:
    if i in res:
        res[i] += 1
    else:
        res[i] = 1
res = sorted(res.items(), key = lambda x: -x[1])

for a, b in res:
    for j in range(b):
        print(str(a)+" ",end="")
