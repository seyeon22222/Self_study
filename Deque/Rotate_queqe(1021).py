from collections import deque
import sys
if __name__ == "__main__":
    n, m = list(map(int, (sys.stdin.readline().split())))
    val = list(map(int, (sys.stdin.readline().split())))
    res = deque()
    for i in range (1, n+1):
        res.append(i)
    res_val = 0
    left = 0
    right = 0
    for i in val:
        while 1:
            if res[0] == i:
                break
            if res.index(i) > (len(res) // 2):
                res.rotate(1)
                res_val += 1
            elif res.index(i) <= (len(res) // 2):
                res.rotate(-1)
                res_val += 1
        res.popleft()
    print(res_val)
