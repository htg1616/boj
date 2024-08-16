import sys
import heapq
input = sys.stdin.readline

def find(u):
    if u != parent[u]:
        parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    root1 = find(u)
    root2 = find(v)
    if root1 != root2:
        if rank[root1] < rank[root2]:
            parent[root1] = root2
        elif rank[root1] > rank[root2]:
            parent[root2] = root1
        else:
            parent[root2] = root1
            rank[root1] += 1

n = int(input())
parent = [i for i in range(n)]
rank = [1] * (n)
priorq = []
arrx = []
arry = []
for _ in range(n):
    x, y = map(float, input().split())
    arrx.append(x)
    arry.append(y)
for i in range(n):
    for j in range(i+1, n):
        d = ((arrx[i] - arrx[j])**2 + (arry[i] - arry[j])**2) ** 0.5
        heapq.heappush(priorq, (d, i, j))

ans = 0
while priorq:
    d, i, j = heapq.heappop(priorq)
    if find(i) != find(j):
        ans += d
        union(i, j)
print(ans)