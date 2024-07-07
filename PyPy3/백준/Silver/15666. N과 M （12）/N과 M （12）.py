n, m = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()

seqs_set = set()
seq = []
def dfs(index):
    if len(seq) == m:
        seqs_set.add(tuple(seq))
        return
    for i in range(index, n):
        seq.append(nums[i])
        dfs(i)
        seq.pop()
dfs(0)
for seq in sorted(seqs_set):
    print(*seq)