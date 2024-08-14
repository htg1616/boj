import sys
from collections import deque
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for line in graph:
    line.sort()

cnt = 1
visited = [0]*(n+1)
q = deque([r])
visited[r] = cnt
while q:
    now = q.popleft()
    for next in graph[now]:
        if not visited[next]:
            cnt += 1
            visited[next] = cnt
            q.append(next)
print(*visited[1:], sep='\n')