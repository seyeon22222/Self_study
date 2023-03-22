# 인덱스로 접근 시, 시간초과 발생 코드
# if __name__ == "__main__":
#     num = int(input())
#     for i in range(num):
#         testc = list(input())
#         tests = []
#         cursor = len(tests)
#         for k in range(len(testc)):
#             if testc[k] == '<':
#                 if cursor != 0:
#                     cursor -= 1
#             elif testc[k] == '>':
#                 if cursor != len(tests):
#                     cursor += 1
#             elif testc[k] == '-':
#                 if tests and (cursor != 0) :
#                     cursor -= 1
#                     del tests[cursor]
#             else:
#                 tests.insert(cursor, testc[k])
#                 cursor += 1
#         print(''.join(tests))
if __name__ == "__main__":
    num = int(input())
    for i in range(num):
        testc = list(input())
        tests1 = []
        tests2 = []
        for k in testc:
            if k == '<':
                if tests1:
                    tests2.append(tests1.pop())
            elif k == '>':
                if tests2:
                    tests1.append(tests2.pop())
            elif k == '-':
                if tests1:
                    tests1.pop()
            else:
                tests1.append(k)
        print(''.join(tests1 + list(reversed(tests2))))