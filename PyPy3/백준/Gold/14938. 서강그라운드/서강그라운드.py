import sys
import heapq
input = sys.stdin.readline

n, m, r = map(int, input().split())
items = list(map(int, input().split()))
graph = [[] for _ in range(n)]
for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a-1].append((l, b-1)) #거리, 비용 순
    graph[b-1].append((l, a-1))

max_item = 0
for start in range(n):
    heap = []
    distance = [int(1e8)]*n
    distance[start] = 0
    heapq.heappush(heap, (0, start))
    while heap:
        dist, now = heapq.heappop(heap)
        if distance[now] < dist:
            continue

        for d, next in graph[now]:
            if dist+d < distance[next]:
                distance[next] = dist+d
                heapq.heappush(heap, (distance[next], next))

    item = 0 
    for i in range(n):
        if distance[i] <= m:
            item += items[i]
    max_item = max(max_item, item)
print(max_item)