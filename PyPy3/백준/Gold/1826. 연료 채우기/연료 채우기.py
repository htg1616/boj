import heapq, sys
input = sys.stdin.readline

n = int(input())
oils = [tuple(map(int, input().split())) for _ in range(n)]
oils.sort()
l, p = map(int, input().split())

maxheap = []
idx = 0
cnt = 0
while(p < l and cnt < n):
    while idx < n and oils[idx][0] <= p:
        heapq.heappush(maxheap, -oils[idx][1])
        idx += 1
    if not maxheap:
        break
    p -= heapq.heappop(maxheap)
    cnt += 1

if l > p:
    print(-1)
else:
    print(cnt)