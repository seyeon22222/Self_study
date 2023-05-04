def nm4(start):
    if len(ans) == m:
        print(' '.join(map(str, ans)))
        return
    for i in range(start, n + 1):
        ans.append(i)
        nm4(i)
        ans.pop()


n, m = map(int, input().split())
ans = []
nm4(1)
