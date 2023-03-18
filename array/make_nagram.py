str1 = input()
str2 = input()
count1 = [0] * 26
count2 = [0] * 26
res = 0;
for i in str1:
    count1[ord(i) - ord('a')] += 1
for j in str2:
    count2[ord(j) - ord('a')] += 1
for i in range(26):
    res += abs(count1[i] - count2[i])
print(res)