sq_nums = [i**2 for i in range(1, 224)]
n = int(input())
dp = [-1]*(n+1)
dp[0] = 0
for i in range(1, n+1):
    cands = []
    for j in sq_nums:
        if i-j >= 0:
            cands.append(dp[i-j]+1)
    dp[i] = min(cands)
print(dp[n])