import sys
sys.setrecursionlimit = int(1e9)

n = int(input())
cnt1 = 0
cnt2 = 0

def fib1(n):
    global cnt1
    if n == 1 or n == 2:
        cnt1 += 1
        return 1
    else:
        return fib1(n-1) + fib1(n-2)

cache = [0] * (n+1)
def fib2(n):
    global cnt2
    cache[1] = 1
    cache[2] = 1
    for i in range(3, n+1):
        cache[i] = cache[i-1] + cache[i-2]
        cnt2 += 1
    return cache[n]

fib1(n)
fib2(n)
print(cnt1, cnt2)