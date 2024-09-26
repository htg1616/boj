import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

st = [1]
visited = [False] * (n+1)
visited[1] = True
cnt = 0
while st:
    now = st.pop()
    for nxt in graph[now]:
        if not visited[nxt]:
            visited[nxt] = True
            st.append(nxt)
            cnt += 1
print(cnt)
