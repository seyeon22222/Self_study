num = int(input())
arr = []
for _ in range(num):
	x, y = list(map(int, input().split()))
	arr.append([x, y])
arr.sort()
for i in range(num):
	print(arr[i][0], arr[i][1])