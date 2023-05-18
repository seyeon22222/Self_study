from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 탐색하는 함수
def bfs(x, y, state):
    q.append((x, y))
    visited[x][y] = 1
    cnt = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 12 and 0 <= ny < 6:
                if not visited[nx][ny] and arr[nx][ny] == state:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
                    cnt += 1
    if cnt >= 4:
        return state
    return None

# 4개 이상 일 때, 터트리는 함수
def bang(state):
    for i in range(12):
        for j in range(6):
            if visited[i][j] == 1 and arr[i][j] == state:
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

    q = deque()
    check = 0
    for i in range(12):
        for j in range(6):
            if arr[i][j] != '.':
                visited = [[0] * 6 for _ in range(12)]
                state = bfs(i, j, arr[i][j])
                if state is not None:
                    bang(state)
                    check = 1
    if check == 0:
        break
    ans += 1
    re_arr()
print(ans)
