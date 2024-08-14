import sys
input = sys.stdin.readline

n = int(input())
if n == 1:
    print(0)
    exit(0)
    
nums = [True] * (n+1)
primes = []
for i in range(2, int(n**0.5) + 2):
    if nums[i]:
        for j in range(2*i, n+1, i):
            nums[j] = False
for i in range(2, n+1):
    if nums[i]:
        primes.append(i)

start = end = 0
sum = primes[0]
ans = 0
while True:
    if sum == n:
        ans += 1
    if sum > n:
        sum -= primes[start]
        start += 1
    elif sum <= n:
        end += 1
        if end >= len(primes):
            break
        sum += primes[end]
print(ans)