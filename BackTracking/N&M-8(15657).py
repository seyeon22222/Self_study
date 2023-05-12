def nm8(start):
    if len(res) == m:
        print(' '.join(map(str, res)))
        return
    for i in range(start, len(ans)):
        res.append(ans[i])
        nm8(i)
        res.pop()


n, m = map(int, input().split())
ans = list(map(int, input().split()))
ans = sorted(ans)
res = []
nm8(0)
