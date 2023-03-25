if __name__ == "__main__":
    num = int(input())
    stack = []
    res = []
    target = []
    count = 1
    for i in range(num):
        tar = int(input())
        #tar 만큼 count를 증가시켜서 스택에 추가
        while count <= tar:
           stack.append(count)
           res.append('+')
           count += 1
        #스택에서 맨 마지막 인덱스의 값이 tar과 동일하면
        #타겟에다가 추가하고, 스택에서 제거
        #이렇게 가능한 이유는 스택이 LIFO방식이라서 가능
        #따라서 이부분에서 TRUE, FALSE를 판별 가능
        if stack[-1] == tar:
            target.append(stack.pop())
            res.append('-')
        else:
            continue
    #스택에 값이 있다는 것은 수열 생성이 불가능한 경우
    if stack :
        print("NO")
    else:
        for j in res:
            print(j)
