from collections import deque
import sys
sys.setrecursionlimit(10000)

dx = [1, -1, 0 , 0]
dy = [0, 0, 1, -1]

def bfs(x,y):
    q.append((x,y))
    visited[x][y] = 1
    while q:
        x,y = q.popleft()
        for i in range(4):
            newX = x + dx[i]
            newY = y + dy[i]
            if not visited[newX][newY] and graph[newX][newY]:
                visited[newX][newY] = 1
                q.append((newX,newY))



if __name__ == "__main__":
    num = int(input())
    for _ in range(num):
        col, row, cnt = list(map(int, input().split()))
        graph = [[0] * 60 for _ in range(60)]
        visited = [[0] * 60 for _ in range(60)]
        for i in range(cnt):
            dot_col, dot_row = list(map(int, input().split()))
            graph[dot_row + 1][dot_col + 1] = 1
        ans = 0
        q = deque()
        for i in range(1, row + 1):
            for j in range(1, col + 1):
                if not visited[i][j] and graph[i][j]:
                    bfs(i, j)
                    ans += 1
        print(ans)