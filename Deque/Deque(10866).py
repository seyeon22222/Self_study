from collections import deque
import sys
if __name__ == "__main__":
    num = int(input())
    res = deque()
    for i in range(num):
        order = sys.stdin.readline().split()
        res_or = order[0]
        if res_or == 'push_front':
            res.appendleft(order[1])
        elif res_or == 'push_back':
            res.append(order[1])
        elif res_or == 'pop_front':
            if res:
                print(res.popleft())
            else:
                print(-1)
        elif res_or == 'pop_back':
            if res:
                print(res.pop())
            else:
                print(-1)
        elif res_or == 'size':
            print(len(res))
        elif res_or == 'empty':
            if res:
                print(0)
            else:
                print(1)
        elif res_or == 'front':
            if res:
                print(res[0])
            else:
                print(-1)
        elif res_or == 'back':
            if res:
                print(res[len(res) - 1])
            else:
                print(-1)