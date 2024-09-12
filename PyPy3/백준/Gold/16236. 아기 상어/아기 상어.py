import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
pool = [list(map(int, input().split())) for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    global time, cnt, size, rescue
    pool[x][y] = 0
    q = deque()
    visited = [[-1]*n for _ in range(n)]
    q.append((x, y))
    visited[x][y] = 0

    hunt_list = []
    change_time = 0
    while not hunt_list and q:
        change_time += 1
        new_q = deque()
        while q:
            x, y = q.popleft()
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if 0 > nx or n <= nx or 0 > ny or n <= ny or visited[nx][ny] != -1:
                    continue
                if pool[nx][ny] > size:
                    continue
                if pool[nx][ny] != 0 and pool[nx][ny] < size:
                    hunt_list.append((nx, ny))
                new_q.append((nx, ny))
                visited[nx][ny] = visited[x][y] + 1
        q = new_q

    if not hunt_list:
        rescue = True
        return 0, 0
    
    time += change_time
    hunt_list.sort()
    hunt_x, hunt_y = hunt_list[0]
    cnt += 1
    if cnt == size:
        size += 1
        cnt = 0
    
    return hunt_x, hunt_y

time = 0
rescue = False
size = 2
cnt = 0

fx, fy = -1, -1
for x in range(n):
    for y in range(n):
        if pool[x][y] == 9:
            fx, fy = x, y
while not rescue:
    fx, fy = bfs(fx, fy)
print(time)