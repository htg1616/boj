import sys
from collections import deque
input = sys.stdin.readline

n, l = map(int, input().split())
a = list(map(int, input().split()))
dq = deque()
for i in range(n):
    while dq and dq[0][1] <= i-l:
        dq.popleft()
    while dq and dq[-1][0] >= a[i]:
        dq.pop()
    dq.append((a[i], i))
    print(dq[0][0], end = ' ')