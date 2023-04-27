def Color(n, r, c):
    global white, blue
    pos = n // 2
    cnt_num = graph[r][c]
    for i in range(r, r + n):
        for j in range(c, c + n):
            if graph[i][j] != cnt_num:
                Color(pos, r, c)
                Color(pos, r, c + pos)
                Color(pos, r + pos, c)
                Color(pos, r + pos, c + pos)
                return
    if cnt_num == 0:
        white += 1
        return
    else:
        blue += 1
        return


n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
blue = 0
white = 0
Color(n, 0, 0)
print(white)
print(blue)
