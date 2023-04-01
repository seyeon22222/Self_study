#시간 초과 난 코드 -> 배열을 뒤집는것 때문에 시간초과
# from collections import deque
# import sys
# if __name__ == "__main__":
#     test = int(input())
#     for i in range (test):
#         func = sys.stdin.readline()
#         arr_num = int(sys.stdin.readline())
#         arr = sys.stdin.readline().rstrip()[1:-1] #개행문자 제거해서 입력을 받음
#         res = deque(arr.split(',')) #'[',']'를 제외하고 ,으로 구분되어 있는 값들을 res에 저장
#         for k in func:
#             flag = 0
#             if k == 'R':
#                 res.reverse()
#             if k == 'D':
#                 if res:
#                     res.popleft()
#                 else:
#                     flag = 1
#                     break
#         if flag == 1:
#             print("error")
#         else:
#             res = list(res)
#             print("[" + ','.join(res) + "]")

from collections import deque
import sys
if __name__ == "__main__":
    test = int(input())
    for i in range (test):
        func = sys.stdin.readline()
        arr_num = int(sys.stdin.readline())
        arr = sys.stdin.readline().rstrip()[1:-1] #개행문자 제거해서 입력을 받음
        res = deque(arr.split(',')) #'[',']'를 제외하고 ,으로 구분되어 있는 값들을 res에 저장
        rev_flag = 0
        for k in func:
            flag = 0
            if k == 'R':
                rev_flag += 1
            elif k == 'D':
                if res and rev_flag % 2 == 0 and arr_num != 0:
                    res.popleft()
                elif res and rev_flag % 2 == 1 and arr_num != 0:
                    res.pop()
                else:
                    flag = 1
                    break
        if flag == 1:
            print("error")
        else:
            res = list(res)
            if rev_flag % 2 == 1:
                res.reverse()
            print("[" + ','.join(res) + "]")
