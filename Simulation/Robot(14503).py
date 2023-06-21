n, m = list(map(int, input().split()))
r, c, d = map(int, input().split())
map = [list(map(int, input().split()))for _ in range(n)]
# 북, 서, 남, 동 회전 / dx[0] : 북
dx=[-1, 0, 1, 0]
dy=[0, 1, 0, -1]
visited = [[0] * m for _ in range(n)]
# d -> 방향이며, 0 : 북, 1 : 서, 2: 남, 3: 동
visited[r][c] = 1
cnt = 1

while 1:
	flag = 0
	for _ in range(4):
		d = (d + 3) % 4
		nr = r + dx[d]
		nc = c + dy[d]
		if 0 <= nr < n and 0 <= nc < m and map[nr][nc] == 0:
			if visited[nr][nc] == 0:
				visited[nr][nc] = 1
				cnt += 1
				r = nr
				c = nc
				flag = 1
				break
	if flag == 0:
		if map[r-dx[d]][c-dy[d]] == 1:
			print(cnt)
			break
		else:
			r, c = r - dx[d], c - dy[d]