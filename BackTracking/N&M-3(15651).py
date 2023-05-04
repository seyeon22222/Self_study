def nm3():
    if len(ans) == m:
        print(' '.join(map(str, ans)))
        return
    for i in range(1, n + 1):
        ans.append(i)
        nm3()
        ans.pop()


n, m = map(int, input().split())
ans = []
nm3()
