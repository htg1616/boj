import sys
input = sys.stdin.readline

def find(u):
    if u == parent[u]:
        return u
    parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    root1 = find(u)
    root2 = find(v)
    if root1 != root2:
        parent[root2] = root1
        cnt[root1] += cnt[root2]
    return cnt[root1]

t = int(input())
for __ in range(t):
    parent = {}
    cnt = {}
    f = int(input())
    for _ in range(f):
        a, b = input().split()
        for i in (a, b):
            if i not in parent:
                parent[i] = i
                cnt[i] = 1
        print(union(a, b))