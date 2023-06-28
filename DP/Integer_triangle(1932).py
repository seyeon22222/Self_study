n = int(input())
tr = [list(map(int, input().split())) for _ in range(n)]
for i in range(1, n):
    for j in range(len(tr[i])):
        if j == 0:
            tr[i][j] += tr[i - 1][j]
        elif j == len(tr[i]) - 1:
            tr[i][j] += tr[i - 1][j - 1]
        else:
            tr[i][j] += max(tr[i - 1][j - 1],tr[i - 1][j])
print(max(tr[n - 1]))