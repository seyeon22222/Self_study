num1 = int(input())
num2 = int(input())
num3 = int(input())
res_num = list(str(num1 * num2 * num3))  # 곱해진 int값을 str로 바꾸어서 배열로 변경
# 예시. 150 * 266 * 427 = 17037300으로 res_num = [1,7,0,3,7,3,0,0] 으로 입력되어 있음
for i in range(0, 10):
    print(res_num.count(str(i)))  # i값이 int값이므로 이를 str로 변경해서 이를 res_num에 있는 개수를 count해줌
