a,b,c = map(int,input().split())
#분할 정복
#-> 큰 계산값을 단순해질 때까지 나누어서 계산하는방법
#-> 재귀함수를 사용해서 단순할때 까지 반복
# 2^32 를 구하기 위해서 -> 2^16 * 2^16으로 쪼개는 방식
# 2^31 -> 2^15 * 2^15 * 2
def mul(a,b,c):
    if b == 1:
        return a % c
    elif b % 2 == 0:
        return (mul(a, b//2, c) ** 2) % c
    else:
        return((mul(a, b//2, c) ** 2) * a) % c
print(mul(a,b,c))


