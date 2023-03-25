# 시간초과 나는 코드 -> 인덱스로 접근하기 때문에 최악의 경우 시간복잡도가 O(n^2)
# num = int(input())
# val = list(map(int, input().split()))
# res = []
#
# while val:
#     k = val.pop()
#     a = len(val)
#     flag = 0
#     if a == 0:
#         res.append(0)
#         break
#     while k > val[a - 1]:
#         a -= 1
#         if a == 0:
#             break
#     res.append(a)
#
# res.reverse()
# res = list(map(str, res))
# print(' '.join(res))

num = int(input())
val = list(map(int, input().split()))
res = [0] * num
stack = []
#스택에 현재 탑의 인덱스들을 저장
for i in range(num):
    #스택이 비어있지 않고, 스택의 마지막값이 들어온 값보다 작을경우 그 스택을 제거
    while stack and val[stack[-1]] < val[i]:
        stack.pop()
    #스택이 비어있지 않고, 마지막값이 들어온값보다 클때 -> 조건 만족
    #정답의 위치에 해당 인덱스값 + 1을 저장
    if stack:
        res[i] = stack[-1] + 1
    #스택에 인덱스 저장
    stack.append(i)

res = list(map(str, res))
print(' '.join(res))