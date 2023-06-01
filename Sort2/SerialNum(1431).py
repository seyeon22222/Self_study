def atoi(arr):
    res = 0
    for i in range(len(arr)):
        if '0' <= arr[i] <= '9':
            res += int(arr[i])
    return res


n = int(input())
arr = []
for _ in range(n):
    arr.append(input())

for i in range(n - 1):
    for j in range(i + 1, n):
        if len(arr[i]) > len(arr[j]):
            temp = arr[j]
            arr[j] = arr[i]
            arr[i] = temp
        elif len(arr[i]) == len(arr[j]):
            index1 = atoi(arr[i])
            index2 = atoi(arr[j])
            if index1 == index2:
                if arr[i] > arr[j]:
                    temp = arr[j]
                    arr[j] = arr[i]
                    arr[i] = temp
            elif index1 > index2:
                temp = arr[j]
                arr[j] = arr[i]
                arr[i] = temp

for i in range(len(arr)):
    print(arr[i])
