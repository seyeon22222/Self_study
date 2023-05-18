from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 탐색하는 함수
def bfs(x, y):
    q = deque()
    q.append((x, y))
    visited[x][y] = 1
    temp.append((x, y))
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 12 and 0 <= ny < 6:
                if not visited[nx][ny] and arr[nx][ny] == arr[x][y]:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
                    temp.append((nx,ny))

# 4개 이상 일 때, 터트리는 함수
def bang(temp):
    for i, j in temp:
        arr[i][j] = '.'

# 터트린 후, 아래로 내리는 함수
def re_arr():
    for i in range(6):
        for j in range(10, -1, -1):
            for k in range(11, j, -1):
                if arr[j][i] != "." and arr[k][i] == ".":
                    arr[k][i] = arr[j][i]
                    arr[j][i] = "."
                    break


arr = [list(input()) for _ in range(12)]
ans = 0
while True:
    visited = [[0] * 6 for _ in range(12)]
    check = 0
    for i in range(12):
        for j in range(6):
            if arr[i][j] != '.' and not visited[i][j]:
                temp = []
                bfs(i, j)
                if len(temp) >= 4:
                    bang(temp)
                    check = 1
    if check == 0:
        break
    ans += 1
    re_arr()
print(ans)
