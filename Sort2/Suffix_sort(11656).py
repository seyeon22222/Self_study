arr = input()
arr_len = len(arr)
res = []
for i in range(0, arr_len):
    res.append(arr[i:])
res.sort()
for i in res:
    print(i)
