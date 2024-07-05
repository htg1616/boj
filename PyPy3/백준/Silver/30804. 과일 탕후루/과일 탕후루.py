from re import L


n = int(input())
s = list(map(int, input().split()))

max_len = 0
interval_cnt = [0]*10
end = 0

def check_cnt(interval_cnt):
    cnt0 = 0
    for i in interval_cnt:
        if i==0:
            cnt0 += 1
    return cnt0 >= 8

for start in range(n):
    while(check_cnt(interval_cnt) and end<n):
        max_len = max(max_len, end-start)
        interval_cnt[s[end]] += 1
        end += 1
    if check_cnt(interval_cnt):
        max_len = max(max_len, end-start)
    interval_cnt[s[start]] -= 1
print(max_len)
