import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
f = [0] * (int(1e6)+1)
for i in arr:
    f[i] += 1
ans = [-1] * n
stack = []
for i in range(n):
    while stack and f[arr[stack[-1]]] < f[arr[i]]:
        ans[stack.pop()] = arr[i]
    stack.append(i)
print(*ans)