def nm6(start):
    if len(res) == m:
        print(' '.join(map(str, res)))
        return
    for i in range(start, len(ans)):
        res.append(ans[i])
        nm6(i + 1)
        res.pop()


n, m = map(int, input().split())
ans = list(map(int, input().split()))
res = []
ans = sorted(ans)
nm6(0)
