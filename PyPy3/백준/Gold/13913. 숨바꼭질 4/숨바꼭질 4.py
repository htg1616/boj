from collections import deque

n, k = map(int, input().split())
visited = [-1] * (100001)
before = [-1] * (100001)

q = deque([n])
while True:
    now = q.popleft()
    if now == k:
        break
    for next in [now+1, now-1, 2*now]:
        if 0 <= next <= 100000 and visited[next] == -1:
            visited[next] = True
            before[next] = now
            q.append(next)
path = deque([k])
now = k
while now != n:
    now = before[now]
    path.appendleft(now)
print(len(path) - 1)
print(*path)