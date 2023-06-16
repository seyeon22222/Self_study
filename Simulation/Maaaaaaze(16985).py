from collections import deque
from itertools import permutations

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]


cube = [[list(map(int, input().split())) for _ in range(5)] for _ in range(5)] # 입력 배열
visited = [[[0] * 5 for _ in range(5)] for _ in range(5)] # bfs를 위한 방문배열
visited_num = 0
ans = float('inf')

def check_ans():
    for combination in permutations(range(5), 5):
        set_cube(combination, 0)
    print(ans if ans != float('inf') else -1)


def set_cube(combination, idx):
    global cube
    if ans == 12:
        return
    if idx == 5:
        check_cube(combination)
        return
    for _ in range(4):
        rotate(combination[idx])
        set_cube(combination, idx + 1)


def check_cube(combination):
    global ans, visited, visited_num
    temp_cube = []
    for i in combination:
        temp_cube.append(cube[i])
    visited_num += 1
    if temp_cube[0][0][0] != 1 or temp_cube[4][4][4] != 1:
        return
    visited_num += 1
    arr = [0,0,0]
    q = deque([arr + [0]])
    visited[0][0][0] = visited_num
    while q:
        z, y, x, cnt = q.pop()
        if cnt >= ans:
            continue
        if 4 == z and 4 == y and 4 == x:
            ans = min(ans, cnt)
            break
        for d in range(6):
            nz = z + dz[d]
            ny = y + dy[d]
            nx = x + dx[d]
            if 0 <= nx < 5 and 0 <= ny < 5 and 0 <= nz < 5 and temp_cube[nz][ny][nx] != 0 and visited[nz][ny][nx] != visited_num:
                visited[nz][ny][nx] = visited_num
                q.appendleft((nz, ny, nx, cnt + 1))


def check_valid(z, y, x, temp_cube):
    if z < 0 or y < 0 or x < 0 or z >= 5 or y >= 5 or x >= 5:
        return False
    elif temp_cube[z][y][x] == 0:
        return False
    elif visited[z][y][x] == visited_num:
        return False
    return True

def rotate(idx):
    global cube

    tmp = []
    for row in cube[idx]:
        tmp_row = []
        for num in row:
            tmp_row.append(num)
        tmp.append(tmp_row)

    for x in range(5):
        for y in range(5):
            cube[idx][4 - x][y] = tmp[y][x]

check_ans()
