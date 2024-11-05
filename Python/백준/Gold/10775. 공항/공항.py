import sys

input = lambda: sys.stdin.readline().rstrip()

sys.setrecursionlimit(10**5)
g = int(sys.stdin.readline())
p = int(sys.stdin.readline())

parent = [i for i in range(g + 1)]

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

count = 0
for _ in range(p):
    gi = int(input())
    gate = find(gi)
    if gate == 0:
        break
    parent[gate] = gate - 1
    count += 1

print(count)