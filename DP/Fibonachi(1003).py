t = int(input())
for _ in range(t):
    n = int(input())
    dp = []
    dp.append((1, 0))
    dp.append((0, 1))
    for i in range(2, n + 1):
        dp.append((dp[i - 1][1], dp[i - 1][0] + dp[i - 1][1]))
    print(dp[n][0], dp[n][1])