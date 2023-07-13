n = int(input())
arr = list(map(int, input().split()))
# oper -> 0: + 1: - 2: x 3: /
oper = list(map(int, input().split()))
ans_min = float('inf')
ans_max = float('-inf')
def dfs(dp, ans, plus, minus, multi, div):
    global ans_min, ans_max
    if dp == n:
        ans_max = max(ans, ans_max)
        ans_min = min(ans, ans_min)
        return
    if plus:
        dfs(dp + 1, ans + arr[dp], plus - 1, minus, multi, div)
    if minus:
        dfs(dp + 1, ans - arr[dp], plus, minus - 1, multi, div)
    if multi:
        dfs(dp + 1, ans * arr[dp], plus, minus, multi - 1, div)
    if div:
        dfs(dp + 1, int(ans / arr[dp]), plus, minus, multi, div - 1)
dfs(1, arr[0], oper[0], oper[1], oper[2], oper[3])
print(ans_max)
print(ans_min)