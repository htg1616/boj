from itertools import permutations
k = int(input())
ineq = input().split()
table = []
min_num = int(1e10)
max_num = 0
for permutation in permutations(range(k+1)):
    chk = True
    for i in range(k):
        if ineq[i] == '<':
            if not permutation[i] < permutation[i+1]:
                chk = False
        if ineq[i] == '>':
            if not permutation[i] > permutation[i+1]:
                chk = False
    if not chk:
        continue

    num = 0
    for i in permutation:
        num = num*10 + i
    min_num = min(num, min_num)
    max_num = max(num, max_num)

max_num += int(str(9-k)*(k+1))
print(max_num)
if(len(str(min_num)) == k+1):
    print(min_num)
else:
    print(0, min_num, sep = '')