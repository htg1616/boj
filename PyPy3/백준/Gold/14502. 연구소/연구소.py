import sys
input = sys.stdin.readline

def infect(mod_graph):
    stack = viruses[:]
    while stack:
        x, y = stack.pop()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and mod_graph[nx][ny] == 0:
                mod_graph[nx][ny] = 2
                stack.append((nx, ny))
    cnt = 0
    for x in range(n):
        for y in range(m):
            if mod_graph[x][y] == 0:
                cnt += 1
    return cnt
        
n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
blanks = [(x, y) for x in range(n) for y in range(m) if graph[x][y] == 0]
viruses = [(x, y) for x in range(n) for y in range(m) if graph[x][y] == 2]
dx = [-1, 1, 0 ,0]
dy = [0, 0, -1, 1]

max_cnt = 0
for i in range(len(blanks)):
    for j in range(i+1, len(blanks)):
        for k in range(j+1, len(blanks)):
            mod_graph = [line[:] for line in graph]
            blank1 , blank2, blank3 = blanks[i], blanks[j], blanks[k]
            mod_graph[blank1[0]][blank1[1]] = 1
            mod_graph[blank2[0]][blank2[1]] = 1
            mod_graph[blank3[0]][blank3[1]] = 1
            max_cnt = max(max_cnt, infect(mod_graph))

print(max_cnt)