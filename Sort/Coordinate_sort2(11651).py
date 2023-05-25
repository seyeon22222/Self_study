num = int(input())
arr = []
for _ in range(num):
	x, y = list(map(int, input().split()))
	arr.append([y, x])
arr.sort()
for i in range(num):
	print(arr[i][1], arr[i][0])