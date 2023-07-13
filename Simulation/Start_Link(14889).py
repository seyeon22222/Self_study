#dfs를 통한 풀이
# n = int(input())
# graph = [list(map(int, input().split())) for i in range(n)]
# visited = [False for _ in range(n)]
# ans = float('inf')
#
# def dfs(dp, idx):
#     global ans
#     if dp == n // 2:
#         start, link = 0, 0
#         for i in range(n):
#             for j in range(n):
#                 if visited[i] and visited[j]:
#                     start += graph[i][j]
#                 elif not visited[i] and not visited[j]:
#                     link += graph[i][j]
#         ans = min(ans, abs(start - link))
#         return
#
#     for i in range(n):
#         if not visited[i]:
#             visited[i] = 1
#             dfs(dp + 1, idx + 1)
#             visited[i] = 0
# dfs(0, 0)
# print(ans)

# 조합을 이용한 풀이
import itertools
n = int(input())
graph = [list(map(int, input().split())) for i in range(n)]
mem = [i for i in range(n)]
ans = float('inf')

for team in itertools.combinations(mem, n//2):
    start, link = 0, 0
    # 리스트끼리의 뺄셈을 하는방법은 아래처럼 list(set - set)을 통해 진행
    team2 = list(set(mem) - set(team))
    for i,j in itertools.combinations(team, 2):
        start += graph[i][j]
        start += graph[j][i]
    for i,j in itertools.combinations(team2, 2):
        link += graph[i][j]
        link += graph[j][i]
    ans = min(ans, abs(start - link))
print(ans)