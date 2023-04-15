import sys
sys.setrecursionlimit(10**7)

def dfs(x):
    global cnt
    visited[x] = True
    cycle.append(x)
    if not visited[select[x]]:
        dfs(select[x])
    else:
        if select[x] in cycle:
            cnt += cycle[cycle.index(select[x]):]




tc = int(input())
for _ in range(tc):
    student = int(input())
    select = [0] + list(map(int,input().split()))
    visited = [False] * (student + 1)
    cnt = []
    for i in range(1, student + 1):
        if not visited[i]:
            cycle = []
            dfs(i)
    print(student - len(cnt))