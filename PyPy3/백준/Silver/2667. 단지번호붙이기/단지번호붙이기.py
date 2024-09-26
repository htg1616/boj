import sys
input = lambda : sys.stdin.readline().strip()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(sy, sx):
    cnt = 0
    st = [(sy, sx)]
    visited[sy][sx] = True
    while st:
        y, x = st.pop()
        cnt += 1
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0<=ny<n and 0<=nx<n and graph[ny][nx] == 1 and not visited[ny][nx]:
                visited[ny][nx] = True
                st.append((ny, nx))
    return cnt


n = int(input())
graph = [list(map(int, list(input()))) for _ in range(n)]
visited = [[False]*n for _ in range(n)]
arr = []
for y in range(n):
    for x in range(n):
        if graph[y][x] == 1 and not visited[y][x]:
            arr.append(dfs(y, x))
print(len(arr))
print(*sorted(arr), sep = '\n')
