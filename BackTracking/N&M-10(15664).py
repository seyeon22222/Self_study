def nm10(start):
    if len(res) == m:
        print(' '.join(map(str, res)))
        return
    flag = 0
    for i in range(start, n):
        if not visited[i] and flag != ans[i]:
            visited[i] = 1
            res.append(ans[i])
            flag = ans[i]
            nm10(i)
            visited[i] = 0
            res.pop()

n, m = map(int, input().split())
ans = list(map(int, input().split()))
ans = sorted(ans)
visited = [0] * n
res = []
nm10(0)
