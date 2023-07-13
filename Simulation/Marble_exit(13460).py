from collections import deque
n, m = list(map(int, input().split()))
graph = [list(map(str, input())) for _ in range(n)]
for y in range(n):
    for x in range(m):
        if graph[y][x] == 'R':
            r_x, r_y = y, x
        if graph[y][x] == 'B':
            b_x, b_y = y, x
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
q = deque()


def move(x, y, i):
    move_cnt = 1
    while 1:
        move_cnt += 1
        nx = x + dx[i]
        ny = y + dy[i]
        if graph[nx][ny] == 'O':
            return (nx, ny, move_cnt)
        if graph[nx][ny] == '#':
            return (x, y, move_cnt - 1)
        x, y = nx, ny

def bfs(rx, ry, bx, by):
    visited = [[[[0] * m for _ in range(n)] for _ in range(m)] for _ in range(n)]
    q.append((rx, ry, bx, by))
    visited[rx][ry][bx][by] = 1
    while q:
        rx, ry, bx, by = q.popleft()
        if visited[rx][ry][bx][by] > 11:
            continue
        if graph[rx][ry] == 'O':
            return visited[rx][ry][bx][by] - 1
        for i in range(4):
            nrx, nry, cnt_r = move(rx, ry, i)
            nbx, nby, cnt_b = move(bx, by, i)
            if graph[nbx][nby] == 'O':
                continue
            if nrx == nbx and nry == nby:
                if cnt_r > cnt_b:
                    nrx -= dx[i]
                    nry -= dy[i]
                else:
                    nbx -= dx[i]
                    nby -= dy[i]
            if visited[nrx][nry][nbx][nby] != 0:
                continue
            visited[nrx][nry][nbx][nby] = visited[rx][ry][bx][by] + 1
            q.append((nrx, nry, nbx, nby))
    return -1

print(bfs(r_x, r_y, b_x, b_y))
