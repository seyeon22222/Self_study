from collections import deque
from itertools import permutations


def check_ans():
    # 순열로 5! = 120번 반복문 실행
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
    # 모든 경우의 수를 도는 반복문
    # 4번을 돌기 때문에, 90도씩 모든 경우를 도는경우
    # 5! * 4**5 = 122880번 반목
    for _ in range(4):
        cube[combination[idx]] = rotate(cube[combination[idx]])
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
    q = deque([[0, 0, 0, 0]])
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


def rotate(cube):
    temp = [[0] * 5 for _ in range(5)]
    for i in range(5):
        for j in range(5):
            temp[j][4 - i] = cube[i][j]
    return temp


dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]
cube = [[list(map(int, input().split())) for _ in range(5)] for _ in range(5)] # 입력 배열
visited = [[[0] * 5 for _ in range(5)] for _ in range(5)] # bfs를 위한 방문배열
visited_num = 0
ans = float('inf')
check_ans()
