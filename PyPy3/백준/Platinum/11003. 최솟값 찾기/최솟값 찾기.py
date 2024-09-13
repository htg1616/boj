import sys, heapq
input = sys.stdin.readline

n, l = map(int, input().split())
a = list(map(int, input().split()))
q = []
for i in range(len(a)):
    heapq.heappush(q, (a[i], i))
    while q and q[0][1] <= i-l:
        heapq.heappop(q)
    print(q[0][0], end = ' ')
