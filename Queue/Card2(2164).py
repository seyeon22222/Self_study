from collections import deque
if __name__ == "__main__":
    num = int(input())
    res = deque([i for i in range(1, num + 1)])
    for i in range(num - 1):
        res.popleft()
        res.append(res.popleft())
    print(res[0])
