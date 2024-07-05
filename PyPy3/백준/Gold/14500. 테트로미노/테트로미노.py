import sys
input = sys.stdin.readline

def summax_rect(rect): #x로는 2, y로는 3인 직사각형 입력받음
    ans = 0
    sum_rect = 0
    for x in range(2):
        for y in range(3):
            sum_rect += rect[x][y]
    points = [(x,y) for x in range(2) for y in range(3)]
    for i in range(5):
        for j in range(i+1, 6):
            x1, y1 = points[i]
            x2, y2 = points[j]
            if (x1, y1, x2, y2) != (0, 1, 1, 1) and not(abs(x1-x2)==1 and abs(y1-y2)==1):
                sum_tetra = sum_rect - rect[x1][y1] - rect[x2][y2]
                ans = max(ans, sum_tetra)
    return ans

n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]

max_cnt = 0
for x in range(n-3):
    for y in range(m):
        line = 0
        for x_ in range(4):
            line += paper[x+x_][y]
        max_cnt = max(max_cnt, line)

for x in range(n):
    for y in range(m-3):
        line = 0
        for y_ in range(4):
            line += paper[x][y+y_]
        max_cnt = max(max_cnt, line)

for x in range(n-2):
    for y in range(m-1):
        rect = [[0]*2 for _ in range(3)]
        for x_ in range(3):
            for y_ in range(2):
                rect[x_][y_] = paper[x+x_][y+y_]
        rect = list(map(list, zip(*rect)))
        max_cnt = max(max_cnt, summax_rect(rect))

for x in range(n-1):
    for y in range(m-2):
        rect = [[0]*3 for _ in range(2)]
        for x_ in range(2):
            for y_ in range(3):
                rect[x_][y_] = paper[x+x_][y+y_]
        max_cnt = max(max_cnt, summax_rect(rect))

print(max_cnt)