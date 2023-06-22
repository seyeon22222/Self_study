n = int(input())
dp = [0] * (n + 1)
prefix = [0] * (n + 1)
for i in range(2, n + 1):
    dp[i] = dp[i - 1] + 1
    prefix[i] = i - 1
    if i % 2 == 0 and dp[i] > dp[i // 2] + 1:
        dp[i] = dp[i//2] + 1
        prefix[i] = i // 2
    if i % 3 == 0 and dp[i] > dp[i // 3] + 1:
        dp[i] = dp[i//3] + 1
        prefix[i] = i // 3
print(dp[n])
cnt = n
while 1:
    print(cnt, end=' ')
    if cnt == 1:
        break
    cnt = prefix[cnt]