std_num = list(map(int, input().split()))
res = 0
male = [0] * 6
female = [0] * 6
# 각 성별의 배열에 학년별로 저장
for i in range(std_num[0]):
    gen, grade = list(map(int, input().split()))
    if gen == 1:
        male[grade - 1] += 1
    else:
        female[grade - 1] += 1
#나머지가 있으면 나눈값 + 1
#나머지가 없으면 몫
for k in range(len(male)):
    if (male[k] > 0):
        if (male[k] % std_num[1] != 0):
            res += male[k] // std_num[1] + 1
        else:
            res += male[k] // std_num[1]
for k in range(len(female)):
    if (female[k] > 0):
        if (female[k] % std_num[1] != 0):
            res += female[k] // std_num[1] + 1
        else:
            res += female[k] // std_num[1]
print(res)