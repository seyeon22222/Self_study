import sys
n = int(input())
arr = list(map(int, sys.stdin.readline().split()))
sum_arr= [0] * n
sum_arr[0] = arr[0]
for i in range(1, n):
    for j in range(i):
        if arr[j] < arr[i]:
            sum_arr[i] = max(sum_arr[i], sum_arr[j] + arr[i])
        else:
            sum_arr[i] = max(sum_arr[i], arr[i])
print(max(sum_arr))