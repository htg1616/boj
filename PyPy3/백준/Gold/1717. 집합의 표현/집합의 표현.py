import sys
input = sys.stdin.readline

n, m  = map(int, input().split())
parent = [i for i in range(n+1)]

def find(u):
    if u == parent[u]:
        return u
    else:
        parent[u] = find(parent[u])
        return parent[u]

def union(u, v):
    root1 = find(u)
    root2 = find(v)
    parent[root2] = root1

for _ in range(m):
    op, a, b = map(int, input().split())
    if op == 0:
        union(a, b)
    elif op == 1:
        print("YES" if find(a) == find(b) else "NO")