import sys
input = sys.stdin.readline
t = int(input())

def gcd(a, b):
    while b!=0:
        a, b = b, a%b
    return a

for _ in range(t):
    m, n, x, y = map(int, input().split())
    L = m * n // gcd(n, m)
    ans = -1
    for i in range(x, L+1, m):
        if i%n == y%n:
            ans = i
    print(ans)