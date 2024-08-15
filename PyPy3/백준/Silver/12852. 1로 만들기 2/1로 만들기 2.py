from collections import deque

n = int(input())

visited = [-1] * (10**6+1)
visited[n] = 0
before = [-1] * (10**6+1)
q = deque([n])
while q:
    now = q.popleft()
    if now == 1:
        break
    nextlist = [now-1]
    if now % 2 == 0:
        nextlist.append(now//2)
    if now % 3 == 0:
        nextlist.append(now//3)
    for next in nextlist:
        if visited[next] == -1:
            visited[next] = visited[now] + 1
            before[next] = now
            q.append(next)

print(visited[1])
path = deque([1])
now = 1
while before[now] != -1:
    path.appendleft(before[now])
    now = before[now]
print(*path)