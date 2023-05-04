def nm5():
    if len(res) == m:
        print(' '.join(map(str, res)))
        return
    for i in ans:
        if i not in res:
            res.append(i)
            nm5()
            res.pop()


n, m = map(int, input().split())
ans = list(map(int, input().split()))
res = []
ans = sorted(ans)
nm5()
