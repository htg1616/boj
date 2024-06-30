import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    if b not in graph[a]:
        graph[a].append(b)
        graph[b].append(a)

def bfs(start):
    q = deque()
    q.append(start)
    dist = [-1] * (n+1)
    dist[start] = 0
    dist[0] = 0
    while q:
        now = q.popleft()
        for next in graph[now]:
            if dist[next] == -1:
                dist[next] = dist[now] + 1
                q.append(next)
    return sum(dist)

min_idx = 0
min_bacon = 123456789
for i in range(1, n+1):
    bacon = bfs(i)
    if bacon < min_bacon:
        min_idx = i
        min_bacon = bacon
print(min_idx)