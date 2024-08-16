a, b, c = sorted(map(int, input().split()))
c = min(c, a + b - 1)
print(a + b + c)