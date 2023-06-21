import sys

n, m = map(int, sys.stdin.readline().split())
number = list(map(int, sys.stdin.readline().split()))
d = [0]
temp = 0
for i in number:
    temp += i
    d.append(temp)

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    print(d[j] - d[i - 1])