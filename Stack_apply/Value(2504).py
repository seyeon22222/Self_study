if __name__ == "__main__":
    val = input()
    weight = 1
    cnt = 0
    res = []
    for i in range(len(val)):
        if val[i] == '(':
            res.append(val[i])
            weight *= 2
        elif val[i] == '[':
            res.append(val[i])
            weight *= 3
        elif val[i] == ')':
            if not res or res[-1] != '(':
                cnt = 0
                break
            if val[i-1] == '(':
                cnt += weight
            weight //= 2
            res.pop()
        elif val[i] == ']':
            if not res or res[-1] != '[':
                cnt = 0
                break
            if val[i-1] == '[':
                cnt += weight
            weight //= 3
            res.pop()
    if res:
        print("0")
    else:
        print(cnt)