import sys
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for line in graph:
    line.sort(reverse=True)

cnt = 0
visited = [0]*(n+1)
stack = [r]
while stack:
    now = stack.pop()
    if not visited[now]:
        cnt += 1
        visited[now] = cnt
    for next in graph[now]:
        if not visited[next]:
            stack.append(next)
print(*visited[1:], sep='\n')