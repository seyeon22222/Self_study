num = int(input())
lst = []
for i in range(num):
	age, name = list(input().split())
	lst.append([int(age), i, name])
lst.sort()
for i in range(num):
	print(lst[i][0], lst[i][2])