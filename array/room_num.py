room_num = input()
res = [0] * 10
for i in range(0, len(room_num)):
    res_num = int(room_num[i])
    if (res_num == 6):
        res[9] += 1
    res[res_num] += 1

print(max(res))
