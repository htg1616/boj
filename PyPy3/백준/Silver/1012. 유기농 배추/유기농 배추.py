import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(y, x):
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= ny < n and 0 <= nx < m and ground[ny][nx] == 1:
            ground[ny][nx] = 2
            dfs(ny, nx)

t = int(input())

for __ in range(t):
    m, n, k = map(int, input().split())

    #ground에서 ground[y][x]는
    #0은 배추가 심어지지 않은 땅
    #1은 배추가 심어져있고 방문하지 않은 땅
    #2는 배추가 심어져있고 방문한 땅
    ground = [[0]*m for _ in range(n)]
    for _ in range(k):
        x, y = map(int, input().split())
        ground[y][x] = 1
    cnt = 0

    for y in range(n):
        for x in range(m):
            if ground[y][x] == 1:
                cnt += 1
                dfs(y, x)
    print(cnt)