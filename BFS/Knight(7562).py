from collections import deque

tcase = int(input())
dx = [-1, 1, 2, 2, 1, -1, -2, -2]
dy = [2, 2, 1, -1, -2, -2, -1, 1]

def bfs():
    while q:
        x, y = q.popleft()
        if x == wx and y == wy:
            return graph[x][y] - 1
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < length and 0 <= ny < length and graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                q.append((nx, ny))

for i in range(tcase):
    length = int(input())
    x,y = map(int,input().split())
    wx, wy = map(int,input().split())
    graph = [[0] * length for _ in range(length)]
    q = deque()
    graph[x][y] = 1
    q.append((x,y))
    print(bfs())
