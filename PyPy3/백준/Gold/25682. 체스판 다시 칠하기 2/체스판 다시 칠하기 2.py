import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
board = [input().strip() for _ in range(n)]

arr1 = [[0] * (m+1) for _ in range(n+1)] #standard1 기준
arr2 = [[0] * (m+1) for _ in range(n+1)] #standard2 기준
standard1 = [['W' if (i+j)%2 else 'B' for j in range(m)] for i in range(n)]
standard2 = [['B' if (i+j)%2 else 'W' for j in range(m)] for i in range(n)]
for i in range(n):
    for j in range(m):
        arr1[i+1][j+1] = arr1[i+1][j] + arr1[i][j+1] - arr1[i][j]
        arr2[i+1][j+1] = arr2[i+1][j] + arr2[i][j+1] - arr2[i][j]
        if board[i][j] != standard1[i][j]:
            arr1[i+1][j+1] += 1
        if board[i][j] != standard2[i][j]:
            arr2[i+1][j+1] += 1

ans = k*k
for i in range(n-k+1):
    for j in range(m-k+1):
        ans = min(ans, arr1[i+k][j+k] - arr1[i][j+k] - arr1[i+k][j] + arr1[i][j])
        ans = min(ans, arr2[i+k][j+k] - arr2[i][j+k] - arr2[i+k][j] + arr2[i][j])
print(ans)