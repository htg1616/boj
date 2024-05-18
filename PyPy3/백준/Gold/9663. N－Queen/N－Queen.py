import itertools
n = int(input())
board = [] #각 행에 퀸이 놓아져있는 얄번호 저장, 없을 경우는 -1 저장
count = 0
def possible_pos(next):
    if next in board:
        return False
    l = len(board)
    for i in range(l):
        if abs(l-i) == abs(next-board[i]):
            return False
    return True

def dfs(row):
    global count
    if row == n:
        count += 1
        return
    for next in range(n):
        if possible_pos(next):
            board.append(next)
            dfs(row+1)
            board.pop()

dfs(0)
print(count)