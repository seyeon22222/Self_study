import sys

n = int(input())
arr = []
for _ in range(n):
    arr.append(int(sys.stdin.readline()))

arr = sorted(arr)
for i in range(len(arr) - 1, -1, -1):
    print(arr[i])
