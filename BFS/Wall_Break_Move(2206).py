from collections import deque

def bfs():
    while q:
        x, y, z = q.popleft()
        if x == n - 1 and y == m - 1:
            break
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] == 0 and visited[nx][ny][z] == 0:
                    visited[nx][ny][z] = visited[x][y][z] + 1
                    q.append((nx, ny, z))
                elif graph[nx][ny] == 1 and z == 0 and visited[nx][ny][z + 1] == 0:
                    visited[nx][ny][z + 1] = visited[x][y][z] + 1
                    q.append((nx,ny, z + 1))

n, m = map(int,input().split())
graph = [list(map(int, input().rstrip())) for _ in range(n)]
visited = [[[0]*2 for _ in range(m)] for _ in range(n)]
visited[0][0][0] = 1
q = deque()
q.append((0,0,0))
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
ans = 0
bfs()
if visited[n - 1][m - 1][0] == 0 and visited[n - 1][m - 1][1] == 0:
    print(-1)
elif visited[n - 1][m - 1][0] != 0:
    ans = visited[n - 1][m - 1][0]
    print(ans)
elif visited[n - 1][m - 1][1] != 0:
    ans = visited[n - 1][m - 1][1]
    print(ans)
