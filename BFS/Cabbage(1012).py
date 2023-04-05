if __name__ == "__main__":
    num = int(input())
    col, row, cnt = list(map(int, input().split()))
    for i in range(cnt):
        dot_col, dot_row = list(map(int, input().split()))
