from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
def bfs(x, y, state):
    q.append((x, y))
    visited[x][y] = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 6 and 0 <= ny < 12:
                if not visited[nx][ny] and arr[nx][ny] == state:
                    q.append((nx, ny))
                    visited[nx][ny] = 1


arr = [list(input()) for _ in range(12)]
visited = [[0] * 6 for _ in range(12)]
q = deque()
for i in range(12):
    for j in range(6):
        if not visited[i][j] and arr[i][j] != '.':
            bfs(i, j, arr[i][j])
print(visited)
