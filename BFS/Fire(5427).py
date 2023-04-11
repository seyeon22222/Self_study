from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

tc = int(input())

def f_bfs():
    flen = len(f)
    for i in range(flen):
        x, y = f.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if graph[nx][ny] != '#' and graph[nx][ny] != '*':
                    graph[nx][ny] = '*'
                    f.append((nx,ny))

def q_bfs():
    while q:
        qlen = len(q)
        for i in range(qlen):
            x,y = q.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                print(graph)
                print(visited)
                if 0 <= nx < h and 0 <= ny < w:
                    if graph[nx][ny] == '.' and visited[nx][ny] == 0:
                        visited[nx][ny] = visited[x][y] + 1
                        q.append((nx,ny))
                else:
                    return visited[x][y]
        f_bfs()
    return 'IMPOSSIBLE'

for _ in range(tc):
    w, h = map(int, input().split())
    graph = []
    for i in range(h):
        graph.append(list(input()))
    visited = [[0] * w for _ in range(h)]
    q = deque()
    f = deque()
    ans = 0
    for i in range(h):
        for j in range(w):
            if graph[i][j] == '*':
                f.append((i,j))
            if graph[i][j] == '@':
                q.append((i,j))
                visited[i][j] = 1
    f_bfs()
    ans = q_bfs()
    print(ans)
