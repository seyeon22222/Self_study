n = int(input())
#자료구조 딕셔너리를 사용하기 위해서 딕셔너리 생성
arr = {}
for _ in range(n):
    temp = int(input())
    #딕셔너리안에 key값이 이미 존재하는지 판별
    #이미 존재한다면 딕셔너리의 키의 값에 1을 증가
    if temp in arr:
        arr[temp] += 1
    #없으면 딕셔너리의 키값 생성
    else:
        arr[temp] = 1
#딕셔너리를 sorted를 사용해서 정렬ㅋ
#arr.items를 통해서 딕셔너리에서 key-value값을 반환
#key=lambda를 통해서 각 쌍을 정렬할 값을 지정하는것으로
#-x[1]을 통해서 value값을 내림차순으로 정렬하고
#x[0]을 통해서 key값을 오름차순으로 정렬을 진행
arr = sorted(arr.items(), key=lambda x: (-x[1], x[0])
             )
print(arr[0][0])
