import heapq
import sys
input = sys.stdin.readline

n = int(input())
nums = [int(input()) for _ in range(n)]
heapq.heapify(nums)

cnt = 0
while len(nums) >= 2:
    a = heapq.heappop(nums)
    b = heapq.heappop(nums)
    cnt += a+b
    heapq.heappush(nums, a+b)
print(cnt)