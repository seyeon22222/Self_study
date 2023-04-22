from collections import deque

dx = [-1, 1, 2, 2, 1, -1, -2, -2, 1, -1, 0, 0]
dy = [2, 2, 1, -1, -2, -2, -1, 1, 0, 0, 1, -1]
dxx = [1, -1, 0, 0]
dyy = [0, 0, 1, -1]

def bfs(k):
    while q:
        x, y, cnt = q.popleft()
        if x == h - 1 and y == w - 1:
            return visited[x][y][cnt]
        if cnt > 0:
            for i in range(8):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < h and 0 <= ny < w:
                    if not visited[nx][ny][cnt - 1] and not graph[nx][ny]:
                        visited[nx][ny][cnt - 1] = visited[x][y][cnt] + 1
                        q.append((nx, ny, cnt - 1))
        for i in range(4):
            kx = x + dxx[i]
            ky = y + dyy[i]
            if 0 <= kx < h and 0 <= ky < w:
                if not visited[kx][ky][cnt] and not graph[kx][ky]:
                    visited[kx][ky][cnt] = visited[x][y][cnt] + 1
                    q.append((kx, ky, cnt))
    return -1

k = int(input())
w, h = map(int,input().split())
graph = [list(map(int,input().split())) for _ in range(h)]
visited = [[[0 for _ in range(k + 1)] for _ in range(w)] for _ in range(h)]
q = deque()
q.append((0,0,k))
print(bfs(k))