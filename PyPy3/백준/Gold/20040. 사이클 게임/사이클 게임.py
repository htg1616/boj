import sys
sys.setrecursionlimit = int(1e6)
input = sys.stdin.readline

def find(u):
    if u != parent[u]:
        parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    root1 = find(u)
    root2 = find(v)
    
    if root1 != root2:
        if rank[root1] > rank[root2]:
            parent[root2] = root1
        elif rank[root1] < rank[root2]:
            parent[root1] = root2
        else:
            parent[root2] = root1
            rank[root1] += 1

n, m = map(int, input().split())
parent = list(range(n))
rank = [1] * n
ans = 0

for i in range(1, m + 1):
    a, b = map(int, input().split())
    if find(a) == find(b):
        ans = i
        break
    union(a, b)

print(ans)
