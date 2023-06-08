import sys

def get_cnt(a, b):
    cnt = 0
    idx = 0
    for i in range(n):
        while idx < m:
            if a[i] > b[idx]:
                idx += 1
            else:
                break
        cnt += idx
    return(cnt)


T = int(input())
for _ in range(T):
    n,m = list(map(int, input().split()))
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    a.sort()
    b.sort()
    print(get_cnt(a,b))


