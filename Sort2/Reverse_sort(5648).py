import sys
#sys.stdin.read 이렇게 사용하면 ctrl+D, 즉 EOF가 입력될때까지 입력을 받음
input = sys.stdin.read
#파이썬에서 *을 사용하면 입력값이 정해지지 않았을 때를 의미(가변인자)
n, *arr = input().split()
for i in range(len(arr)):
    #파이썬에서 리스트를 뒤집는 방법으로, [::-1]은 슬라이싱 기법
    #요소를 처음부터 끝까지 역순으로 뒤집는 것을 의미
    arr[i] = arr[i][::-1]
arr = list(map(int, arr))
arr = sorted(arr)
for i in range(len(arr)):
    print(arr[i])