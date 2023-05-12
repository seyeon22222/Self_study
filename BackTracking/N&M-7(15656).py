def nm7():
    if len(res) == m:
        print(' '.join(map(str, res)))
        return
    for i in ans:
        res.append(i)
        nm7()
        res.pop()


n, m = map(int, input().split())
ans = list(map(int, input().split()))
ans = sorted(ans)
res = []
nm7()