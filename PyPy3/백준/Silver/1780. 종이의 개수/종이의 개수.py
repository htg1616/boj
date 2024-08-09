import sys
input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    for j in range(n):
        arr[i][j] += 1

def check(x0, x1, y0, y1):
    bool = True
    for i in range(x0, x1):
        for j in range(y0, y1):
            if arr[i][j] != arr[x0][y0]:
                bool = False
    return bool

def solve(x0, x1, y0, y1):
    if check(x0, x1, y0, y1):
        ans = [0] * 3
        ans[arr[x0][y0]] = 1
        return ans
    ans = [0] * 3
    xs = [x0, (2 * x0 + x1)//3, (x0 + 2 * x1)//3, x1]
    ys = [y0, (2 * y0 + y1)//3, (y0 + 2 * y1)//3, y1]
    for i in range(3):
        for j in range(3):
            for index, w in enumerate(solve(xs[i], xs[i+1], ys[j], ys[j+1])):
                ans[index] += w
    return ans

print(*solve(0, n, 0, n), sep='\n')