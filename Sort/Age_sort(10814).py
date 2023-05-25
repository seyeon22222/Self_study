#시간초과 코드
# num = int(input())
# age_arr = []
# name_arr = []
# for _ in range(num):
#   age, name = list(input().split())
#   age_arr.append(int(age))
#   name_arr.append(name)
# for i in range(num):
#   j = i + 1
#   for j in range(num -1):
#       if age_arr[j] > age_arr[j + 1]:
#           temp = age_arr[j]
#           age_arr[j] = age_arr[j + 1]
#           age_arr[j + 1] = temp
#           temp = name_arr[j]
#           name_arr[j] = name_arr[j + 1]
#           name_arr[j + 1] = temp
# for i in range(num):
#   print(age_arr[i], end="")
#   print(" " + name_arr[i])
num = int(input())
lst = []
for i in range(num):
    age, name = list(input().split())
    lst.append([int(age), i, name])
lst.sort()
for i in range(num):
    print(lst[i][0], lst[i][2])