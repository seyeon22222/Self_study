n = int(input())
res = [0] * (n + 1)
for i in range(2, n + 1):
    # 2와 3으로 나누어 떨어지지 않는 경우는 -1을 해야함
    res[i] = res[i - 1] + 1
    if i % 2 == 0:
        # 2으로 나누어 떨어질 때, 현재의 값과 2로 나눈 값 + 1
        res[i] = min(res[i], res[i//2] + 1)
    if i % 3 == 0:
        # 3으로 나누어 떨어질 때, 현재의 값과 3로 나눈 값 + 1
        res[i] = min(res[i], res[i//3] + 1)
print(res[n])