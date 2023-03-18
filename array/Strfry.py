num = int(input())
for i in range(num):
    str1, str2 = list(input().split())
    #join함수는 문자열을 결합하는 함수로, list로 받은 str1, str2는 다음과 같은 형태이다.
    #str1 = abc / str2 = bcd(타입은 문자열)
    #이것을 join 함수를 이용해서 하나의 문자열로 합치는데, 이 때, join() 괄호안에 들어가는 함수를 실행시킨 결과를 반환한다.
    #sorted함수를 사용해서 입력받은 리스트를 문자열로 합칠 때, 아스키코드순으로 정렬해서 합쳐준다.
    str1 = ''.join(sorted(str1))
    str2 = ''.join(sorted(str2))
    if str1 == str2:
        print("Possible")
    else:
        print("Impossible")
