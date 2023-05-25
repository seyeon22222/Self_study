from collections import deque
import sys


def rotate_left(q_num, position):
	if q_num < 0 or q[q_num][2] == q[q_num + 1][6]:
		return
	rotate_left(q_num - 1, -position)
	q[q_num].rotate(position)

def rotate_right(q_num, position):
	if q_num > 3 or q[q_num][6] == q[q_num - 1][2]:
		return
	rotate_right(q_num + 1, -position)
	q[q_num].rotate(position)

q = [deque(list(map(int, sys.stdin.readline().rstrip()))) for _ in range(4)]
rotate_num = int(input())
ans = 0
for _ in range(rotate_num):
	q_num, position = list(map(int, input().split()))
	q_num -= 1
	rotate_left(q_num - 1, -position)
	rotate_right(q_num + 1, -position)
	q[q_num].rotate(position)

if q[0][0] == 1:
	ans += 1
if q[1][0] == 1:
	ans += 2
if q[2][0] == 1:
	ans += 4
if q[3][0] == 1:
	ans += 8
print(ans)