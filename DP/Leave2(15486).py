import sys
n = int(sys.stdin.readline())
dp = [0 for i in range(n+1)]
for i in range(1, n + 1):
    t, p = map(int, sys.stdin.readline().split())
    dp[i] = max(dp[i - 1], dp[i])
    if i + t <= n + 1:
        dp[i + t - 1] = max(dp[i - 1] + p, dp[i + t - 1])
print(dp[-1])
