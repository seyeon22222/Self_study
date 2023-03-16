#시간 초과 코드 - 이중 반복문
# size = int(input())
# arr = list(map(int,input().split()))
# x = int(input())
#
# cnt = 0
# for i in range(size):
#     for j in range(i+1,size):
#         if (arr[i] + arr[j] == x):
#             cnt += 1
# print(cnt)

# 투포인터 -> 정렬이 되어있지 않으면 작동하지 않음
# 양쪽에 인덱스를 접근해서 한번에 반복문을 끝내기 위해서 사용
# 특정 조건 마다 왼쪽 인덱스 증가, 오른쪽 인덱스 감소를 사용
# 아래의 코드에서는 합이 작다면 오른쪽 인덱스 감소
# 합이 크다면 왼쪽 인덱스 증가
# 합일경우 왼쪽, 오른쪽 인덱스 증/감소
size = int(input())
arr = list(map(int, input().split()))
x = int(input())

arr.sort()
cnt = 0
right = size - 1
left = 0
while left < right:
    if (arr[left] + arr[right] == x):
        cnt += 1
        left += 1
        right -= 1
    elif (arr[left] + arr[right] > x):
        right -= 1
    else:
        left += 1
print(cnt)