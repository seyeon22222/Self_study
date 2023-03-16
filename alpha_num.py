alpha = [0] * 26
str = input()
str_len = len(str) #len 함수를 이용해서 길이를 구함
for i in range(str_len): #입력된 문자열의 길이만큼 반복문을 진행
    alpha[ord(str[i]) - 97] += 1 #배열에 i번째 인덱스의 값을 ord를 아스키코드값(10진수)로 변환한 뒤 각 배열의 값에 더해줌

for a in range(0,26):
    print(alpha[a], end = ' ')