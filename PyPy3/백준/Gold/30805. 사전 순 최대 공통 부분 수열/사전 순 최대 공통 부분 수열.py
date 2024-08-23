import bisect
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

cache = [[[] for i in range(m+1)] for j in range(n+1)]
for i in range(1, n+1):
    for j in range(1, m+1):
        cand1 = cache[i-1][j][:]
        cand2 = cache[i][j-1][:]
        cand3 = cache[i-1][j-1][:]
        if(a[i-1] == b[j-1]):
            num = a[i-1]
            index = 0
            while(index < len(cand3) and cand3[index] >= num):
                index += 1
            cand3 = cand3[:index]+ [num]
        cache[i][j] = max(cand1, cand2, cand3)

print(len(cache[n][m]))
print(*cache[n][m])