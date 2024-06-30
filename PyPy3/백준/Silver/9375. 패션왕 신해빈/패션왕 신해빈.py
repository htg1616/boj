import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    cnt = dict()
    for i in range(n):
        a, b = input().strip().split()
        cnt[b] = cnt.get(b, 0) + 1
    ans = 1
    for i in cnt.values():
        ans *= i+1
    ans -= 1
    print(ans)