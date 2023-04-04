if __name__ == "__main__":
    num = int(input())
    res_val = 0
    for i in range(num):
        val = input()
        res = []
        for i in val:
            if len(res) == 0 or res[-1] != i:
                res.append(i)
            else:
                res.pop()
        if len(res) == 0:
            res_val += 1
    print(res_val)