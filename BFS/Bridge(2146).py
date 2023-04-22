from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def bridge(cnt):
    global res
    num = [[-1] * n for _ in range(n)]
    q = deque()
    for i in range(n):
        for j in range(n):
            if graph[i][j] == cnt:
                q.append((i, j))
                num[i][j] = 0

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if graph[nx][ny] > 0 and graph[nx][ny] != cnt:
                    res.append(num[x][y])
                    return
                elif num[nx][ny] == -1 and not graph[nx][ny]:
                    num[nx][ny] = num[x][y] + 1
                    q.append((nx, ny))


def island(i, j):
    global cnt
    graph[i][j] = cnt
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n \
                    and graph[nx][ny] and not visited[nx][ny]:
                visited[nx][ny] = 1
                graph[nx][ny] = cnt
                q.append((nx, ny))


n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [[0] * n for _ in range(n)]
q = deque()
res = []
cnt = 1
#섬 구분하는 과정
for i in range(n):
    for j in range(n):
        if graph[i][j] and not visited[i][j]:
            q.append((i, j))
            visited[i][j] = 1
            island(i, j)
            cnt += 1

for k in range(1, cnt):
    bridge(k)

ans = min(res)
print(ans)
