#계란끼리 부딫힐 때 내구도가 무게만큼 감소 / 0이하면 깨짐
def dfs(idx , cnt):
    global ans
    if idx == num:
        ans = max(ans, cnt)
        return
    #현재 계란이 깨졌을 떄
    if arr[idx][0] <= 0:
        dfs(idx + 1, cnt)
    #현재 계란이 안 깨졌을 떄
    else:
        flag = 0
        for j in range(num):
    #자기 자신 또는 이미 깨져있는 경우는 제외
            if idx == j or arr[j][0] <= 0:
                continue
            flag = 1
            arr[idx][0] -= arr[j][1]
            arr[j][0] -= arr[idx][1]
    #한개만 깨졌을 때
            if ((arr[idx][0] <= 0) and (arr[j][0] > 0))\
                or ((arr[idx][0] > 0) and (arr[j][0] <= 0)):
                dfs(idx + 1, cnt + 1)
    #둘 다 깨졌을 때
            elif (arr[idx][0] <= 0) and (arr[j][0] <= 0):
                dfs(idx + 1, cnt + 2)
    #하나도 안깨졌을 때
            else:
                dfs(idx + 1, cnt)
            arr[idx][0] += arr[j][1]
            arr[j][0] += arr[idx][1]
    #한번도 안부딫혔을 때
        if flag == 0:
            dfs(idx + 1, cnt)


num = int(input())
arr = [list(map(int, input().split())) for _ in range(num)]
visited = [0] * num
ans = 0
dfs(0, 0)
print(ans)
