n, m = map(int, input().split())
nums = list(map(int, input().split()))

seqs_set = set()
index_seq = []
def dfs():
    if len(index_seq) == m:
        seqs_set.add(tuple([nums[index] for index in index_seq]))
        return
    for i in range(n):
        if i not in index_seq:
            index_seq.append(i)
            dfs()
            index_seq.pop()
dfs()

for seq in sorted(seqs_set):
    print(*seq)