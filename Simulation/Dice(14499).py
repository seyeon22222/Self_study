# 주사위 평면도는 아래와 같으며, 각각의 인덱스를 적용
# 평상시
# dice[0] = 2 / dice[1] = 4 / dice[2] = 1
# dice[3] = 3 / dice[4] = 5 / dice[5] = 6
# 동쪽으로 굴렸을때
# dice[0] = 2 / dice[1] = 1 / dice[2] = 3
# dice[3] = 6 / dice[4] = 5 / dice[5] = 4
# 서쪽으로 굴렸을때
# dice[0] = 2 / dice[1] = 6 / dice[2] = 4
# dice[3] = 1 / dice[4] = 5 / dice[5] = 3
# 남쪽으로 굴렸을 때
# dice[0] = 6 / dice[1] = 4 / dice[2] = 2
# dice[3] = 3 / dice[4] = 1 / dice[5] = 5
# 북쪽으로 굴렸을 때
# dice[0] = 1 / dice[1] = 4 / dice[2] = 5
# dice[3] = 3 / dice[4] = 6 / dice[5] = 2
#    2
# 4  1(윗면)   3
#    5
#    6(아랫면)
def order_find(order):
    a, b, c, d, e, f = dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]
    # 동
    if order == 1:
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]\
            = a, c, d, f, e, b
    # 서
    elif order == 2:
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] \
            = a, f, b, c, e, d
    # 북
    elif order == 3:
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] \
            = c, b, e, d, f, a
    # 남
    else:
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] \
            = f, b, a, d, c, e

# m X n 크기의 지도, (x,y)에서 시작, k가 명령어의 갯수
n, m, x, y, k = list(map(int, input().split()))
Map = []
dice = [0, 0, 0, 0, 0, 0]
# 명령어 동,서,북,남을 확인하기 위해서 생성
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
# 지도를 입력받음
for _ in range(n):
    Map.append(list(map(int, input().split())))
order = list(map(int,input().split()))
for i in order:
    nx = x + dx[i - 1]
    ny = y + dy[i - 1]
    if not 0 <= nx < n or not 0 <= ny < m:
        continue
    order_find(i)
    if Map[nx][ny] == 0:
        Map[nx][ny] = dice[5]
    else:
        dice[5] = Map[nx][ny]
        Map[nx][ny] = 0
    x, y = nx, ny
    print(dice[2])
