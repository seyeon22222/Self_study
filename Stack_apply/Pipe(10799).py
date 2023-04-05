if __name__ == "__main__":
    val = input()
    res = []
    cnt = 0
    for i in range(len(val)):
        if val[i] == '(':
           res.append(i)
        elif val[i] == ')':
            if res[-1] == i - 1:
                res.pop()
                cnt += len(res)
            else:
                res.pop()
                cnt += 1
    print(cnt)
