import sys
input = sys.stdin.readline

n = int(input())
cards = list(map(int, input().split()))
is_card = [False for _ in range(1_000_001)]
for i in cards:
    is_card[i] = True

cnt_arr = [0 for _ in range(1_000_001)]
for i in sorted(cards):
    for j in range(2*i, 1_000_001, i):
        if is_card[j]:
            cnt_arr[i] += 1
            cnt_arr[j] -= 1

for i in cards:
    print(cnt_arr[i], end=' ')