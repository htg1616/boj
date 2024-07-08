import sys
from itertools import combinations
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

chicks = [(x, y) for x in range(n) for y in range(n) if graph[x][y] == 2]
homes = [(x, y) for x in range(n) for y in range(n) if graph[x][y] == 1]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
ans = int(1e8)
for selected_chicks in combinations(chicks, m):
    total_dist = 0
    for home in homes:
        total_dist += min([abs(chick[0]-home[0]) + abs(chick[1]-home[1]) for chick in selected_chicks])
    ans = min(total_dist, ans)
print(ans)