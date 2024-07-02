import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [0 for _ in range(101)]
for i in range(n):
    a, b = map(int, input().split())
    graph[a] = b
for i in range(m):
    a, b = map(int, input().split())
    graph[a] = b

dist = [-1]*101
dist[1] = 0
q = deque()
q.append(1)
while q:
    now = q.popleft()
    for next in [now+i for i in range(1, 7)]:
        if 1<= next <= 100 and graph[next] != 0:
                next = graph[next]
        if 1<= next <= 100 and dist[next] == -1:
            dist[next] = dist[now] + 1
            q.append(next)
print(dist[100])