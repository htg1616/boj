n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]

def check(left, right, top, bottom):
    chk = paper[top][left]
    for x in range(left, right):
        for y in range(top, bottom):
            if paper[y][x] != chk:
                return -1
    return chk

def solve(left, right, top, bottom):
    if check(left, right, top, bottom) == 0:
        return (1, 0)
    elif check(left, right, top, bottom) == 1:
        return (0, 1)

    midx = (left+right)//2
    midy = (top+bottom)//2

    ans0 = ans1 = 0
    dx = [[left, midx], [midx, right]]
    dy = [[top, midy], [midy, bottom]]
    for x in dx:
        for y in dy:
            ans = solve(*(x+y))
            ans0 += ans[0]
            ans1 += ans[1]
    return (ans0, ans1)

print(*solve(0, n, 0, n), sep='\n')