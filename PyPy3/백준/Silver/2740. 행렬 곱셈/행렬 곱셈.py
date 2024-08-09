import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
m, k = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(m)]

def mul(arr1, arr2):
    ans = [[0]*k for _ in range(n)]
    for i in range(n):
        for j in range(k):
            for l in range(m):
                ans[i][j] += arr1[i][l] * arr2[l][j]
    return ans
for line in mul(a, b):
    print(*line)