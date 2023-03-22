if __name__ == "__main__":
    num, count = list(map(int, input().split()))
    num_list = []
    for i in range(1, num+1):
        num_list.append(i);
    res = []
    idx = 0
    for i in range (num):
        idx += count -1
        if idx >= len(num_list):
            idx = idx % len(num_list)
        res.append(str(num_list.pop(idx)))
    k = ', '.join(res)
    print('<' + k + '>')