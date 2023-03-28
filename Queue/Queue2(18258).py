import sys
from collections import deque
if __name__ == "__main__":
    num = int(input())
    res = deque()
    for i in range(num):
        order = sys.stdin.readline().split()
        res_order = order[0]
        if res_order == 'push':
            res.append(order[1])
        elif res_order == 'front':
            if res:
                print(res[0])
            else:
                print(-1)
        elif res_order == 'size':
            print(len(res))
        elif res_order == 'pop':
            if res:
                print(res.popleft())
            else:
                print(-1)
        elif res_order == 'empty':
            if res:
                print(0)
            else:
                print(1)
        elif res_order == 'back':
            if res:
                print(res[len(res) - 1])
            else:
                print(-1)