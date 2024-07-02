import sys
from collections import deque
input = sys.stdin.readline

def D(n):
    return 2*n%10000
def S(n):
    return (n-1)%10000
def L(n):
    return n%1000*10 + n//1000
def R(n):
    return n//10 + n%10*1000

def solve(a, b):
    distance = [-1]*10000
    distance[a] = ''
    q = deque()
    q.append(a)
    while q:
        now = q.popleft()
        if now == b:
            return distance[b]
        next_list = [D(now), S(now), L(now), R(now)]
        func_list = ['D', 'S', 'L', 'R']
        for i in range(4):
            next = next_list[i]
            if distance[next] == -1:
                distance[next] = distance[now] + func_list[i]
                q.append(next)

t = int(input())
for __ in range(t):
    a, b = map(int, input().split())
    print(solve(a, b))

