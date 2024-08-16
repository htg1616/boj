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

v, e = map(int, input().split())
parent = [i for i in range(v+1)]
rank = [1] * (v+1)
priorq = []
for _ in range(e):
    a, b, c = map(int, input().split())
    heapq.heappush(priorq, (c, a, b))

ans = 0
while priorq:
    c, a, b = heapq.heappop(priorq)
    if find(a) != find(b):
        ans += c
        union(a, b)
print(ans)