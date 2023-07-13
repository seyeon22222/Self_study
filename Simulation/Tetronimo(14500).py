import sys
# ㅜ자 모양
def excp1(x, y):
    if x + 2 >= m or x < 0 or y - 1 < 0 or y >= n:
        return 0
    ans = 0
    ans += graph[y][x]
    ans += graph[y][x + 1]
    ans += graph[y - 1][x + 1]
    ans += graph[y][x + 2]
    return ans
# ㅗ자 모양
def excp2(x, y):
    if x + 2 >= m or x < 0 or y < 0 or y + 1 >= n:
        return 0
    ans = 0
    ans += graph[y][x]
    ans += graph[y][x + 1]
    ans += graph[y + 1][x + 1]
    ans += graph[y][x + 2]
    return ans
# ㅓ자 모양
def excp3(x, y):
    if x >= m or x - 1 < 0 or y < 0 or y + 2 >= n:
        return 0
    ans = 0
    ans += graph[y][x]
    ans += graph[y + 1][x]
    ans += graph[y + 1][x - 1]
    ans += graph[y + 2][x]
    return ans
# ㅏ자 모양
def excp4(x, y):
    if x + 1 >= m or x < 0 or y < 0 or y + 2 >= n:
        return 0
    ans = 0
    ans += graph[y][x]
    ans += graph[y + 1][x]
    ans += graph[y + 1][x + 1]
    ans += graph[y + 2][x]
    return ans

def dfs(x, y, cnt, ans):
    if cnt == 4:
        return res.append(ans)
    ans += graph[y][x]
    for a in range(4):
        nx = x + dx[a]
        ny = y + dy[a]
        if 0 <= nx < m and 0 <= ny < n and not visited[ny][nx]:
            visited[ny][nx] = 1
            dfs(nx, ny, cnt + 1, ans)
            visited[ny][nx] = 0


n, m = list(map(int, sys.stdin.readline().split()))
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [[0] * m for _ in range(n)]
cnt = 0
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
res = []
for y in range(n):
    for x in range(m):
        visited[y][x] = 1
        dfs(x, y, 0, 0)
        visited[y][x] = 0
        res.append(excp1(x, y))
        res.append(excp2(x, y))
        res.append(excp3(x, y))
        res.append(excp4(x, y))
print(max(res))