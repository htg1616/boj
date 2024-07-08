import sys
input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

#가로는 0, 대각선은 1, 세로는 2로 표현
dp = [[[-1]*3 for _ in range(n)] for __ in range(n)]
dx = [1, 1, 0]
dy = [0, 1, 1]
next_types = [[0, 1], [0, 1, 2], [1, 2]]

def solve(x, y, type):
    if dp[x][y][type] != -1:
        return dp[x][y][type]
    if x == n-1 and y == n-1:
        return 1

    ans = 0
    for ntype in next_types[type]:
        nx = x + dx[ntype]
        ny = y + dy[ntype]
        if ntype in [0, 2]:
            if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] == 0:
                ans += solve(nx, ny, ntype)
        elif ntype == 1:
            if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] == 0 and graph[x][ny] == 0 and graph[nx][y] == 0:
                ans += solve(nx, ny, ntype)
    dp[x][y][type] = ans
    return ans

print(solve(0, 1, 2))