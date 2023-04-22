n = int(input())
#규칙1 : 원반은 위에서 부터 꺼냄
#규칙2 : 한번에 하나씩 꺼냄
#규칙3 : 항상 작은 원반이 위에있음
#시작, 보조, 목표 기둥
#hanoi(개수, 시작, 보조, 목표)
def hanoi(n, start, sub, end):
    #원반이 1개면 시작 -> 목표 기둥으로 이동
    if n == 1:
        print(start, end)
        return
    else:
        #보조기둥을 목표로 맨위의 원반을 이동
        hanoi(n-1, start, end, sub)
        print(start,end)
        #보조기둥에 있던 맨위의 원반을 목표기둥으로 이동
        hanoi(n-1, sub, start, end)
sum = 2 ** n - 1
print(sum)
hanoi(n,1,2,3)

#전체 적인 맵 -> 5개 기준
                            #원반 이동
# 5,1,2,3					1 3
# 	4,1,3,2					1 2
# 		3,1,2,3				3 2
# 			2,1,3,2			1 3
# 				1,1,2,3		2 1
# 				1,3,1,2		2 3
# 			2,2,1,3			1 3
# 				1,2,3,1		1 2
# 				1,1,2,3		3 2
# 		3,3,1,2				3 1
# 			2,3,2,1			2 1
# 				1,3,1,2		3 2
# 				1,2,3,1		1 3
# 			2,1,3,2			1 2
# 				1,1,2,3		3 2
# 				1,3,1,2		1 3
# 	4,2,1,3					2 1
# 		3,2,3,1				2 3
# 			2,2,1,3			1 3
# 				1,2,3,1		2 1
# 				1,1,2,3		3 2
# 			2,3,2,1			3 1
# 				1,3,1,2		2 1
# 				1,2,3,1		2 3
# 		3,1,2,3				1 3
# 			2,1,3,2			1 2
# 				1,1,2,3		3 2
# 				1,3,1,2		1 3
# 			2,2,1,3			2 1
# 				1,2,3,1		2 3
# 				1,1,2,3		1 3