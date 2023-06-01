import sys
n = int(sys.stdin.readline())
arr = []
for _ in range(n):
    arr.append(sys.stdin.readline().strip())
arr = set(arr)
arr = list(arr)
arr.sort()
#sort 함수에서 key = len이라고 입력을 해주면, 길이순으로 정렬해줌
arr.sort(key = len)
for i in arr:
    print(i)