from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 빙산이 녹는 정도를 계산하는 BFS
# 또한 visited배열로 빙산의 범위를 체크
def ice_bfs():
    ice = deque()
    while q:
        x, y = q.popleft()
        sea_cnt = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                if graph[nx][ny] != 0:
                    visited[nx][ny] = 1
                    q.append((nx, ny))
                else:
                    sea_cnt += 1
        if sea_cnt > 0:
            ice.append((x, y, sea_cnt))
    return ice

n, m = map(int,input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
ans = 0

while True:
    cnt = 0
    visited = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if graph[i][j] != 0 and not visited[i][j]:
                cnt += 1 #빙산의 개수
                q = deque()
                q.append((i,j))
                visited[i][j] = 1
                ice = ice_bfs()
                while ice:
                    x, y, ice_cnt = ice.pop()
                    # 문제에서 빙산의 높이는 0보다 작아질 수 없다고 명시
                    graph[x][y] = max(graph[x][y]-ice_cnt, 0)
    if cnt == 0:
        print(0)
        exit()
    if cnt > 1:
        print(ans)
        exit()
    ans += 1

