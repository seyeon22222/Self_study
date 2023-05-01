import sys
sys.setrecursionlimit(10000)

def star11(n):
    if n == 3:
        return ['  *  ', ' * * ', '*****']
    recursion = star11(n//2)
    ans = []
    for i in recursion:
        ans.append(' ' * (n//2) + i + ' ' * (n//2))
    for i in recursion:
        ans.append(i + ' ' + i)
    return ans



n = int(input())
res = '\n'.join(star11(n))
print(res)
