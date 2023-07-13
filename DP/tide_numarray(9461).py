n = int(input())
d = [0] * 101
d[1] = 1
d[2] = 1
d[3] = 1
d[4] = 2
d[5] = 2
d[6] = 3
for i in range(7,101):
    d[i] = d[i - 2] + d[i - 3]
for i in range(n):
    print(d[int(input())])