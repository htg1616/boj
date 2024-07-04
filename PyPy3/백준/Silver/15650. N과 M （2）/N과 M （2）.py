n, m = map(int, input().split())

seq = []
def dfs(num):
    if len(seq) == m:
        print(*seq)
        return
    for i in range(num+1, n+1):
        seq.append(i)
        dfs(i)
        seq.pop()
dfs(0)