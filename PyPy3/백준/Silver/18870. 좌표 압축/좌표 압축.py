import sys
input = sys.stdin.readline
n = int(input())
nums = list(map(int, input().split()))
x = [[nums[i], i] for i in range(n)]
x.sort()
temp = x[0][0]
x[0][0] = 0
for i in range(1, n):
    if x[i][0] == temp:
        x[i][0] = x[i-1][0]
    else:
        x[i][0], temp = x[i-1][0]+1, x[i][0]
x.sort(key=lambda x: x[1])
print(*[i[0] for i in x])
