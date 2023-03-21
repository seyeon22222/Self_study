# 시간초과 나는 코드 -> 리스트에서 insert와 del을 사용할경우
# 인덱스를 건드리면서 진행하기 때문에, 최악의 경우 시간복잡도가 O(n)이 됨
# 그래서 시간초과가 발생
# if __name__ == "__main__" :
#     str = list(input())
#     num = int(input()) #반복할 횟수
#     cursor = len(str) #현재 커서의 위치
#     for i in range(num) :
#         fn = input().split()
#         a = fn[0]
#         if a == 'P':
#             str.insert(cursor, fn[1]) #insert는 인덱스와 값을 주면 그 인덱스의 위치에 값을 추가
#             cursor += 1
#         elif a == 'L' and cursor != 0:
#             cursor -= 1
#         elif a == 'D' and cursor != len(str):
#             cursor += 1
#         elif a == 'B' and cursor != 0:
#             del str[cursor] #del은 리스트와 인덱스를 주면 리스트의 해당 인덱스를 제거
#             cursor -= 1
#     print(''.join(str))

# 2개의 스택으로 문제를 풀 경우 시간복잡도가 O(1)로 감소 -> 인데스를 건드릴 필요가 없기 때문
# 스택 -> 자료구조형 중 하나로, 후입선출(LIFO)의 방식을 가지고 있다.
# push : 맨 위에 값 추가, pop : 맨 위에 값 제거 등등의 연산결과들을 가지고 있다.
# 스택 2개를 사용해서 인덱스를 건드리는 것이 아닌, 각각의 스택에서 후입선출의 방식으로 서로의 스택으로 값을 옮기는 방식
import sys #readline을 사용하기 위한 라이브러리
if __name__ == "__main__" :
    str_stack1 = list(input())
    str_stack2 = []
    num = int(input())  # 반복할 횟수
    for i in range (num):
        #input.split을 사용할 경우, for문이 돌 때마다 입력값을 새로 할당받기 떄문에 오래걸림으로 사용 X
        #order = input().split()
        order = sys.stdin.readline().split() #이는 입력된 값을 한번에 입력받아 버퍼에 저장해서 처리하기 때문에 input문보다 처리속도가 빠름
        stack1 = order[0]
        if stack1 == 'L' and str_stack1 : #스택1이 빈 배열이면 실행이 되면 안됨
            str_stack2.append(str_stack1.pop())
            # push와 같은 기능으로 append는 리스트의 가장 마지막에 값을 추가하는 함수
            # pop은 원하는 인덱스의 값을 제거하는데, 인덱스를 주지 않으면 가장 마지막의 인덱스를 제거
            # pop의 경우 제거된 인덱스의 값을 반환
        elif stack1 == 'D' and str_stack2 :
            str_stack1.append(str_stack2.pop())
        elif stack1 == 'B' and str_stack1:
            str_stack1.pop()
        elif stack1 == 'P':
            str_stack1.append(order[1])
    # print(''.join(str_stack1 + str_stack2.reverse())) -> reverse를 쓰면 안됨
    # -> 만일 스택2가 빈 리스트일 경우, 연산자체가 불가능하기 때문에 타입에러를 발생시킴
    #print(''.join(str_stack1 + str_stack2[::-1])) -> 얘도 사용하면 안됨 -> 스택2가 클 경우 슬라이싱하는 과정에서 시간이 많이 소요됨
    #str_stack2[::-1]은 리스트 슬라이싱으로 리스트의 일부분을 불러내기 위해서 사용
    #리스트[시작인덱스:끝인덱스:스텝] 으로 구성되며, 시작인덱스부터 스텝만큼 증가하면서 끝인덱스는 포함하지 않는 방식으로 슬라이싱이 된다.
    #위의 방식에서는 시작,끝인덱스를 명시를 하지 않아서 모든 인덱스를 포함시킨 방식이며
    #만약 스텝이 음수의 값을 가지게 되면 뒤에서부터 슬라이싱이 되며
    #따라서 [::-1]이라고 작성을 할 경우, 해당 리스트를 역순으로 반환한 것
    print(''.join(str_stack1 + list(reversed(str_stack2))))