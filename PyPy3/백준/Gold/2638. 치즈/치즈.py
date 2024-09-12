import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visited = [[False]*m for _ in range(n)]
visited1 = [[False]*m for _ in range(n)]
time = 0

q_init = deque()
for i in range(m):
    q_init.append((-1, i))
    q_init.append((n, i))
for i in range(n):
    q_init.append((i, -1))
    q_init.append((i, m))

q = deque()
def init():
    while q_init:
        x, y = q_init.popleft()
        if 0<=x<n and 0<=y<m:
            q.append((x, y))
            visited1[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<n and 0<=ny<m and paper[nx][ny] == 0 and not visited[nx][ny]:
                visited[nx][ny] = True
                q_init.append((nx, ny))

def air():
    while True:
        cnt = 0
        steps = len(q)
        for i in range(steps):
            x, y = q[i]
            for j in range(4):
                nx, ny = x + dx[j], y + dy[j]
                if 0<=nx<n and 0<=ny<m and paper[nx][ny] == 0 and not visited[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny))
                    cnt += 1
        if cnt == 0:
            break

def cheese():
    steps = len(q)
    count = [[0]*m for _ in range(n)]
    for i in range(steps):
        x, y = q[i]
        for j in range(4):
            nx, ny = x + dx[j], y + dy[j]
            if 0<=nx<n and 0<=ny<m and paper[nx][ny] == 1:
                count[nx][ny] += 1
                if count[nx][ny] >= 2:
                    visited[nx][ny] = True
                    paper[nx][ny] = 0
                    q.append((nx, ny))

init()
time = 0
while any([any(line) for line in paper]):
    cheese()
    air()
    time += 1
print(time)