import sys
if __name__ == '__main__':
    num_order = int(input())
    stack = []
    for i in range(num_order):
        order = sys.stdin.readline().split()
        re_order = order[0]
        if order[0] == 'push':
            stack.append(int(order[1]))
        elif order[0] == 'pop':
            if stack :
                print(stack.pop())
            else:
                print(-1)
        elif order[0] == 'size':
                print(len(stack))
        elif order[0] == 'empty':
            if stack :
                print(0)
            else:
                print(1)
        elif order[0] == 'top':
            if stack :
                print(stack[-1])
            else:
                print(-1)