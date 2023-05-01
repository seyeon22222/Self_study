def star(n):
	pos = n // 3
	if n == 3:
		return ['***', '* *', '***']
	recursion = star(pos)
	stars = []
	for i in recursion:
		stars.append(i * 3)
	for i in recursion:
		stars.append(i + (' ' * pos) + i)
	for i in recursion:
		stars.append(i * 3)
	return stars


n = int(input())
res =  '\n'.join(star(n))
print(res)