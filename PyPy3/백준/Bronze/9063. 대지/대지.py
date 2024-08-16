import sys
input = sys.stdin.readline

n = int(input())
arrx = []
arry = []
for _ in range(n):
    x, y = map(int, input().split())
    arrx.append(x)
    arry.append(y)
print((max(arry) - min(arry)) * ((max(arrx) - min(arrx))))