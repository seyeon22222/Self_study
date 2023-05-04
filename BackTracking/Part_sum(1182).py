import sys
sys.setrecursionlimit(100000)

def sep_sum(idx):
	global ans
	if sum(res) == s and len(res) > 0:
		ans += 1
	for i in range(idx, n):
		res.append(arr[i])
		sep_sum(i + 1)
		res.pop()

n, s = map(int,input().split())
arr = list(map(int,input().split()))
ans = 0
res = []
sep_sum(0)
print(ans)