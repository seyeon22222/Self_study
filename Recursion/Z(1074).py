def z(n, r, c):
    half = n // 2
    if n == 2:
        if r == 0 and c == 0:
            return 0
        elif r == 0 and c == 1:
            return 1
        elif r == 1 and c == 0:
            return 2
        elif r == 1 and c == 1:
            return 3
    else:
        half2 = half * half
        if r < half and c < half:
            return z(n // 2, r, c)
        elif r < half and c >= half:
            return (half2) + z(n // 2, r, c - half)
        elif r >= half and c < half:
            return (half2 * 2) + z(n // 2, r - half, c)
        elif r >= half and c >= half:
            return (half2 * 3) + z(n // 2, r - half, c - half)


n, r, c = map(int, input().split())
res = z(2 ** n, r, c)
print(res)
