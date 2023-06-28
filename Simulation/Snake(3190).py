from collections import deque
n = int(input())
arr = [[0] * n for _ in range(n)]
k = int(input())
for _ in range(k):
    i, j = map(int,input().split())
    arr[i-1][j-1] = 2

L = int(input())
dis = {}
for _ in range(L):
    a, b = map(str,input().split())
    dis[int(a)] = b

sec = 0
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
n_dis = 0
i, j = 0, 0
arr[i][j] = 1
snake = deque()
snake.append((0, 0))
while 1:
    sec += 1
    i += dx[n_dis]
    j += dy[n_dis]
    if i < 0 or i >= n or j < 0 or j >= n:
        break
    if arr[i][j] == 2:
        arr[i][j] = 1
        snake.append((i, j))
    elif arr[i][j] == 0:
        x, y = snake.popleft()
        arr[i][j] = 1
        arr[x][y] = 0
        snake.append((i, j))
    else:
        break
    if sec in dis:
        if dis[sec] == 'D':
            n_dis = (n_dis + 1) % 4
        elif dis[sec] == 'L':
            n_dis = (n_dis - 1) % 4
print(sec)
