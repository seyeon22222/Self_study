def lotto(start):
    if len(ans) == 6:
        print(' '.join(map(str, ans)))
        return
    flag = 0
    for i in range(start, len(s)):
        if flag != s[i]:
            ans.append(s[i])
            lotto(i+1)
            ans.pop()


while 1:
    arr = list(map(int, input().split()))
    k = arr[0]
    s = arr[1:]
    ans = []
    if arr[0] == 0:
        break
    lotto(0)
    print()
