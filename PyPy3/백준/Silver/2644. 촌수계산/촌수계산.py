import sys
input = sys.stdin.readline

INF = int(1e8) #10의 8승

n = int(input())
a, b = map(int, input().split())
m = int(input())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
visited = [False] * (n+1)

def dfs(now, goal):
    #goal에 도달한 경우, 촌수를 반환
    #goal에 도달하지 못한 경우 매우 큰 정수를 반환
    if now == goal:
        return 0
    
    ret = INF
    for nxt in graph[now]:
        if not visited[nxt]:
            visited[nxt] = True
            ret = min(ret, dfs(nxt, goal)+1)
    return ret

visited[a] = True
ans = dfs(a, b)
if ans == INF:
    print(-1)
else:
    print(ans)