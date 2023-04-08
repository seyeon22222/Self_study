from collections import deque
import sys

dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

def bfs():
    while q:
        z, y, x = q.popleft()
        for i in range(6):
            newz = z + dz[i]
            newy = y + dy[i]
            newx = x + dx[i]
            if 0 <= newx < M and 0 <= newy < N and 0 <= newz < H \
                    and not visited[newz][newy][newx] and graph[newz][newy][newx] == 0:
                visited[newz][newy][newx] = 1
                graph[newz][newy][newx] = graph[z][y][x] + 1
                q.append((newz, newy, newx))

M, N, H = map(int, input().split())
graph = [[list(map(int, sys.stdin.readline().split())) for _ in range(N)] for _ in range(H)]
visited = [[[0] * M for _ in range(N)] for _ in range(H)]
q = deque()
ans = 0

for i in range(H):
    for j in range(N):
        for k in range(M):
            if graph[i][j][k] == 1:
                q.append((i,j,k))
bfs()
for i in range(H):
    for j in range(N):
        for k in range(M):
            if graph[i][j][k] == 0:
                print(-1)
                exit(0)
            if graph[i][j][k] > ans:
                ans = graph[i][j][k]
print(ans - 1)
