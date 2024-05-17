import itertools
n, m = map(int, input().split())
max_sum = 0
cards = list(map(int, input().split()))
for i in itertools.combinations(cards, 3):
    if sum(i)<= m:
        max_sum = max(max_sum, sum(i))
print(max_sum) 