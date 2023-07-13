from collections import deque
import copy
n, m = list(map(int, input().split()))
graph = [list(map(int, input().split())) for _ in range(n)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
ans = 0
def bfs():
    global ans
    q = deque()
    temp_graph = copy.deepcopy(graph)
    for i in range(n):
        for j in range(m):
            if temp_graph[i][j] == 2:
                q.append((i, j))
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if temp_graph[nx][ny] == 0:
                temp_graph[nx][ny] = 2
                q.append((nx, ny))
    cnt_0 = 0
    for i in range(n):
        cnt_0 += temp_graph[i].count(0)
    ans = max(cnt_0, ans)

def set_wall(cnt):
    if cnt == 3:
        bfs()
        return
    for a in range(n):
        for b in range(m):
            if graph[a][b] == 0:
                graph[a][b] = 1
                set_wall(cnt + 1)
                graph[a][b] = 0

set_wall(0)
print(ans)