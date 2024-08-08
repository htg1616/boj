import sys
input = sys.stdin.readline
sys.setrecursionlimit = int(1e9)

m, n = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(m)]
cache = [[-1]* n for _ in range(m)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dp(x, y): #(x, y)에서 시작하여 (m-1, n-1)에 도착하는 방법의 수
    if (x, y) == (m-1, n-1):
        graph[m-1][n-1] = 1
        return 1
    if cache[x][y] != -1:
        return cache[x][y]
    ret = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < m and 0 <= ny < n and graph[nx][ny] < graph[x][y]:
            ret += dp(nx, ny)
    cache[x][y] = ret
    return ret

print(dp(0, 0))