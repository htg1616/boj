import sys
input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
r, c, t = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(r)]
aircond = []
for y in range(r):
    for x in range(c):
        if room[y][x] == -1:
            aircond.append((y, x))
            room[y][x] = 0

def diffuse():
    change = [[0]*c for _ in range(r)]
    for y in range(r):
        for x in range(c):
            if (y, x) in aircond:
                continue
            dust = room[y][x]
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if 0 <= ny < r and 0 <= nx < c and (ny, nx) not in aircond:
                    change[ny][nx] += dust//5
                    change[y][x] -= dust//5
    
    for y in range(r):
        for x in range(c):
            room[y][x] += change[y][x]

def circulation():
    y1, x1 = aircond[0]
    y2, x2 = aircond[1]
    
    y, x = y1, x1
    tmp = room[y][x]
    for i in range(4):
        while True:
            ny = y + dy[i]
            nx = x + dx[i]
            if ny < 0 or ny > y1 or nx < 0 or nx >= c:
                break
            room[ny][nx], tmp = tmp, room[ny][nx]
            y, x = ny, nx
    room[y1][x1] = 0

    y, x = y2, x2
    tmp = room[y][x]
    for i in range(4):
        while True:
            ny = y + dy[(4-i)%4]
            nx = x + dx[(4-i)%4]
            if ny < y2 or ny >= r or nx < 0 or nx >= c:
                break
            room[ny][nx], tmp = tmp, room[ny][nx]
            y, x = ny, nx
    room[y2][x2] = 0

for _ in range(t):
    diffuse()
    circulation()
print(sum([sum(line) for line in room]))