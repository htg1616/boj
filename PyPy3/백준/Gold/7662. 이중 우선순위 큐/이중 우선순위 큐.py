import sys, heapq
input = sys.stdin.readline

def sync(arr, deleted):
    while arr and deleted[arr[0][1]]:
        heapq.heappop(arr)

def solve():
    k = int(input())
    minq = []
    maxq = []
    deleted = [False] * (1_000_001)
    for key in range(k):
        op, num = input().split()
        num = int(num)

        if op=='I':
            heapq.heappush(minq, (num, key))
            heapq.heappush(maxq, (-num, key))
            
        elif num == 1:
            sync(maxq, deleted)
            if maxq:
                deleted[maxq[0][1]] = True
                heapq.heappop(maxq)
        elif num == -1:
            sync(minq, deleted)
            if minq:
                deleted[minq[0][1]] = True
                heapq.heappop(minq)
    sync(maxq, deleted)
    sync(minq, deleted)
    if minq and maxq:
        print(-maxq[0][0], minq[0][0])
    else:
        print("EMPTY")


t = int(input())
for _ in range(t):
    solve()
