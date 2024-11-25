import sys
input = lambda : sys.stdin.readline().strip()

n, m = map(int, input().split())
if(100*n >=m):
    print("Yes")
else:
    print("No")