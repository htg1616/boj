import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
degree = [0]*(n+1)
for _ in range(m):
    a, b = map(int, input().split())
    degree[b] += 1
    graph[a].append(b)

zeros = []
for i in range(1, n+1):
    if degree[i] == 0:
        heapq.heappush(zeros, i)

path = []
while zeros:
    now = heapq.heappop(zeros)
    path.append(now)
    for nxt in graph[now]:
        degree[nxt] -= 1
        if degree[nxt] == 0:
            heapq.heappush(zeros, nxt)
print(*path)