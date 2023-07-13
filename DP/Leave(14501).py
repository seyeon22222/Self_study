def dfs(dp, cnt):
    global ans
    if dp >= n:
        ans = max(ans, cnt)
        return
    t = arr[dp][0]
    p = arr[dp][1]
    if t + dp <= n:
        dfs(dp + t, cnt + p)
    dfs(dp + 1, cnt)


n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
ans = float('-inf')
for i in range(n):
    dfs(i, 0)
print(ans)
