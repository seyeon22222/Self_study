# 시간초과 나는 방식 / 10까지는 시간초과가 나지 않으나 그 이후, 1씩 증가할 때마다
# 8배씩 시간이 증가해서 N=14일 때, 약 50분정도 걸리는 코드가 됨 -> 파이썬3 기준
# pypy3로 실행시 통과

def check(res, idx, c):
    for k in range(idx):
        if res[k] == c + idx - k or res[k] == c - idx + k:
            return False
    return True

def Queen(idx, res):
    global ans
    if len(res) == n:
        ans += 1
    for i in range(n):
        if i not in res and check(res, idx, i):
            Queen(idx + 1, res + [i])


n = int(input())
ans = 0
Queen(0, [])
print(ans)
