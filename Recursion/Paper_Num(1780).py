def paper(n, r, c):
    global res, res1, res2
    pos = n // 3
    cnt_num = graph[r][c]
    for i in range(r, r + n):
        for j in range(c, c + n):
            if graph[i][j] != cnt_num:
                paper(pos, r, c)
                paper(pos, r, c + pos)
                paper(pos, r, c + (pos * 2))
                paper(pos, r + pos, c)
                paper(pos, r + pos, c + pos)
                paper(pos, r + pos, c + (pos * 2))
                paper(pos, r + (pos * 2), c)
                paper(pos, r + (pos * 2), c + pos)
                paper(pos, r + (pos * 2), c + (pos * 2))
                return
    if cnt_num == -1:
        res += 1
        return
    elif cnt_num == 0:
        res1 += 1
        return
    elif cnt_num == 1:
        res2 += 1
        return


n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
res = 0
res1 = 0
res2 = 0
paper(n, 0, 0)
print(res)
print(res1)
print(res2)