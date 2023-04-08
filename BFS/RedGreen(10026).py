from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x,y):
    q.append((x, y))
    visited[x][y] = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            newX = x + dx[i]
            newY = y + dy[i]
            if 0 <= newX < num and 0 <= newY < num \
                    and not visited[newX][newY] \
                    and graph[newX][newY] == graph[x][y]:
                visited[newX][newY] = 1
                q.append((newX, newY))

num = int(input())
graph = [list(input()) for _ in range(num)]
visited = [[0] * num for _ in range(num)]
ans = 0
q = deque()
for i in range(num):
    for j in range(num):
        if not visited[i][j]:
            bfs(i,j)
            ans += 1
print(ans, end = ' ')

for i in range(num):
    for j in range(num):
        if graph[i][j] == 'R':
            graph[i][j] = 'G'
ans = 0
visited = [[0] * num for _ in range(num)]
for i in range(num):
    for j in range(num):
        if not visited[i][j]:
            bfs(i,j)
            ans += 1
print(ans)
