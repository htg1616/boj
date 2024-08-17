t = int(input())
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

suma = [0]
sumb = [0]
for i in a:
    suma.append(suma[-1] + i)
for i in b:
    sumb.append(sumb[-1] + i)

dictb = {}
for i in range(m):
    for j in range(i+1, m+1):
        toadd = sumb[j] - sumb[i]
        dictb[toadd] = dictb.get(toadd, 0) + 1

ans = 0
for i in range(n):
    for j in range(i+1, n+1):
        sum = suma[j] - suma[i]
        ans += dictb.get(t - sum, 0)
print(ans)