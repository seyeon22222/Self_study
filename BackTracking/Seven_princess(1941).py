from collections import deque

def bfs(x, y):
    q = deque()
    b_visited = [[0] * 5 for _ in range(5)]
    q.append((x, y))
    b_visited[x][y] = 1
    cnt = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 5 and 0 <= ny < 5:
                if not b_visited[nx][ny] and visited[nx][ny] == 1:
                    q.append((nx, ny))
                    b_visited[nx][ny] = 1
                    cnt += 1
    if cnt == 7:
        return 1
    else:
        return 0

def check():
    for a in range(5):
        for b in range(5):
            if visited[a][b] == 1:
                return bfs(a, b)

def dfs(n, cnt, s_cnt):
    global ans
    if cnt > 7:
        return
    if n == 25:
        #7명이 그룹원이고, 4명이상의 다솜파가 있는지 확인
        if cnt == 7 and s_cnt >= 4:
            #인접해있는지 체크하는 함수(bfs)
            if check():
                ans += 1
        return
    #포함하는 경우
    visited[n // 5][n % 5] = 1
    dfs(n + 1, cnt + 1, s_cnt + int(arr[n // 5][n % 5] == 'S'))
    #포함하지 않는 경우
    visited[n // 5][n % 5] = 0
    dfs(n + 1, cnt, s_cnt)


arr = [list(input()) for _ in range(5)]
visited = [[0] * 5 for _ in range(5)]
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
cnt = 0
s_cnt = 0
ans = 0
dfs(0, 0, 0)
print(ans)
