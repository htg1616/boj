import sys
sys.setrecursionlimit = int(1e9)

n = int(input())
A = list(map(int, input().split()))

s1 = [-1] * n #s1[i] : A[i]가 마지막 수가 되는 부분 증가 수열의 최대 길이
s2 = [-1] * n #s2[i] : A[i]가 첫번째 수가 되는 부분 감소 수열의 최대 길이

def dp1(i):
    if s1[i] != -1:
        return s1[i]
    s1[i] = 1
    for before in range(i):
        if A[before] < A[i]:
            s1[i] = max(s1[i], dp1(before)+1)
    return s1[i]

def dp2(i):
    if s2[i] != -1:
        return s2[i]
    
    s2[i] = 1
    for next in range(i+1, n):
        if A[next] < A[i]:
            s2[i] = max(s2[i], dp2(next)+1)
    return s2[i]

ans = 0
for i in range(n):
    ans = max(ans, dp1(i)+dp2(i)-1)
print(ans)