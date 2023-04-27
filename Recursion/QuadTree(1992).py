def Quad_tree(n, r, c):
    pos = n // 2
    cnt_num = graph[r][c]
    for i in range(r, r + n):
        for j in range(c, c + n):
            if graph[i][j] != cnt_num:
                print("(", end="")
                Quad_tree(pos, r, c)
                Quad_tree(pos, r, c + pos)
                Quad_tree(pos, r + pos, c)
                Quad_tree(pos, r + pos, c + pos)
                print(")", end="")
                return
    if cnt_num == 0:
        print("0", end="")
        return
    if cnt_num == 1:
        print("1", end="")
        return


n = int(input())
graph = [list(map(int, input())) for _ in range(n)]
Quad_tree(n, 0, 0)