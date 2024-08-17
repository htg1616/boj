import copy
board_start=[list(map(int,list(str(input())))) for i in range(9)]
zero_list_start=[]
for x in range(9):
    for y in range(9):
        if board_start[x][y]==0:
            zero_list_start.append([x,y])

def check(a): # 한 줄 또는 한 3*3 정사각형을 검사
    count=[0]*9
    for i in range(9):
        if a[i]!=0:
            count[a[i]-1]+=1
    for i in count:
        if i>=2:
            return False
    return True

def check_list(x,y,board): #어떤 자리의 위치가 입력되었을때 그 위치의 가로,세로,정사각형 check
    output=[]
    a=check([board[i][y] for i in range(9)])
    b=check([board[x][i] for i in range(9)])
    X=x-x%3
    Y=y-y%3
    c=check([board[i][j] for i in range(X,X+3) for j in range(Y,Y+3)])
    if a and b and c:
        return True
    return False

def main(board,zero_list):
    if not zero_list:
        return board
    process=zero_list[0]
    x=process[0]
    y=process[1]
    new_zero_list=zero_list[1:]
    numbers=list(range(1,10))
    a=[board[i][y] for i in range(9)]
    b=[board[x][i] for i in range(9)]
    X=x-x%3
    Y=y-y%3
    c=[board[i][j] for i in range(X,X+3) for j in range(Y,Y+3)]
    for i in a+b+c:
        if i in numbers:
            numbers.remove(i)
    for i in numbers:
        board[x][y]=i
        a=main(board,new_zero_list)
        if a:
            return a
        board[x][y]=0

answer=main(board_start,zero_list_start)
for i in answer:
    print(*i, sep='')