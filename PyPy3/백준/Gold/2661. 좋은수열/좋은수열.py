import sys
input = lambda : sys.stdin.readline().strip()

n = int(input())
ans = []
def f(i):
    for k in range(1, i//2+1):
        if ans[i-k:i] == ans[i-2*k:i-k]:
            return False
    if i == n:
        print("".join(ans))
        return True
    for j in "123":
        ans.append(j)
        if f(i+1):
            return True
        ans.pop()
    return False

f(0)