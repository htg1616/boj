import heapq, sys
input = sys.stdin.readline

n = int(input())
heap = []
for __ in range(n):
    x = int(input())
    if x == 0:
        if len(heap) == 0:
            print(0)
        else:
            abs_num, num = heapq.heappop(heap)
            print(num)
    else:
        heapq.heappush(heap, (abs(x), x))