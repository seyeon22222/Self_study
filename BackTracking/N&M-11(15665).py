def nm11():
    if len(res) == m:
        print(' '.join(map(str, res)))
        return
    flag = 0
    for i in range(n):
        if flag != ans[i]:
            res.append(ans[i])
            flag = ans[i]
            nm11()
            res.pop()

n, m = map(int, input().split())
ans = list(map(int, input().split()))
ans = sorted(ans)
res = []
nm11()
