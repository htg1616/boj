import sys
input = sys.stdin.readline
INF = int(1e8)

v, e = map(int, input().split())
distance = [[INF] * (v+1) for _ in range(v+1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    distance[a][b] = c
for i in range(1, v+1):
    distance[i][i] = 0
for k in range(1, v+1):
    for i in range(1, v+1):
        for j in range(1, v+1):
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

mincycle = INF
for i in range(1, v+1):
    for j in range(i+1, v+1):
        mincycle = min(mincycle, distance[i][j] + distance[j][i])
if mincycle != INF:
    print(mincycle)
else:
    print(-1)