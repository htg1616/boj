n, m = map(int, input().split())
sample1 = ['BWBWBWBW', 'WBWBWBWB']*4
sample2 = ['WBWBWBWB', 'BWBWBWBW']*4
board = [input() for _ in range(n)]
cnt_min = 12345
for i in range(n-7):
    for j in range(m-7):
        cnt1 = 0
        cnt2 = 0
        for y in range(8):
            for x in range(8):
                if board[i+y][j+x] != sample1[y][x]:
                    cnt1 += 1
                if board[i+y][j+x] != sample2[y][x]:
                    cnt2 += 1
        cnt_min = min(cnt_min, cnt1, cnt2)
print(cnt_min)
        