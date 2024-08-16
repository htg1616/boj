import sys
input = sys.stdin.readline


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

n = int(input())
m = int(input())
parent = [i for i in range(n+1)]
for i in range(1, n+1):
    line = list(map(int, input().split()))
    for j in range(1, n+1):
        if line[j-1] == 1:
            union(i, j)
path = list(map(int, input().split()))

ans = "YES"
for i in range(m-1):
    if find(path[i]) != find(path[i+1]):
        ans = 'NO'
print(ans)