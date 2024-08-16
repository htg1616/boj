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
while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break

    parent = [i for i in range(m)]
    rank = [1] * (m)
    priorq = []
    before = 0
    for _ in range(n):
        x, y, z = map(int, input().split())
        heapq.heappush(priorq, (z, x, y))
        before += z

    after = 0
    while priorq:
        z, x, y = heapq.heappop(priorq)
        if find(x) != find(y):
            after += z
            union(x, y)
    print(before - after)