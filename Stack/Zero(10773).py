if __name__ == "__main__":
    num = int(input())
    stack = []
    res_val = 0
    for i in range (num):
        res = int(input())
        if res != 0:
            stack.append(res)
        else:
            stack.pop()
    for k in stack:
        res_val += k
    print(res_val)
