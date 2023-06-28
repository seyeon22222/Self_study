import sys
n = int(input())
num_arr = list(map(int, sys.stdin.readline().split()))
for i in range(1, n):
    num_arr[i] = max(num_arr[i], num_arr[i - 1] + num_arr[i])
print(max(num_arr))
