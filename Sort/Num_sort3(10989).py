import sys

n = int(input())
arr = [0] * 10001
for _ in range(n):
	num = int(sys.stdin.readline().rstrip())
	arr[num] += 1

for i in range(1,10001):
	if arr[i] > 0:
		while (arr[i] > 0):
			print(i)
			arr[i] -= 1