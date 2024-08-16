import sys
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


t = int(input())
for __ in range(t):
    n, m = map(int, input().split())
    parent = [i for i in range (n+1)]
    rank = [1] * (n+1)

    ans = 0
    for _ in range(m):
        a, b = map(int, input().split())
        if find(a) != find(b):
            union(a, b)
            ans += 1
    print(ans)