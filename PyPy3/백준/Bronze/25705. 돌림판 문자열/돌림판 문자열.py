import sys
input = lambda : sys.stdin.readline().strip()

n = int(input())
a = input()
m = int(input())
s = input()

flag = False
for i in s:
    if i not in a:
        print(-1)
        flag = True
        break
if not flag:
    n_pos = n-1
    s_pos = 0
    cnt = 0
    while s_pos < m:
        n_pos = (n_pos+1)%n
        cnt += 1
        if a[n_pos] == s[s_pos]:
            s_pos += 1
    print(cnt)