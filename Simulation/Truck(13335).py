# n개의 트럭
# w대의 트럭이 동시에 올라갈 수 있음
# 다리의 길이는 w단위길이
# 하나의 단위시간에 하나의 단위길이 만큼 이동할 수 있음
# 다리위의 트럭의 무게의 합은 최대하중인 L보다 작거나 같음
# 완전하게 못올라갈 경우 무게에 포함하지 않음

n, w, l = list(map(int, input().split()))
truck = list(map(int, input().split()))
bridge = [0] * w
ans = 0
while bridge:
    ans += 1
    bridge.pop(0)
    if truck:
        if sum(bridge) + truck[0] <= l:
            bridge.append(truck.pop(0))
        else:
            bridge.append(0)
print(ans)