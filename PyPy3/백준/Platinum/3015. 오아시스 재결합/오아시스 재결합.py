'''
import sys
import bisect
input = sys.stdin.readline
INF = 1<<31

n = int(input())
h = [INF] + [int(input()) for _ in range(n)] #bisect 사용하기 위해 음수로 저장
st = [0]
ans = 0
dup_cnt = 0
for i in range(1, n+1):
    check = 0

    p = bisect.bisect_left(st, i, key = lambda x : -h[x])
    ans += p-1

    check += p-1

    if p < len(st):
        ans += i - st[p]

        check += i - st[p]
    while h[st[-1]] < h[i]:
        st.pop()

    if h[st[-1]] == h[i]:
        ans += dup_cnt

        check += dup_cnt
        dup_cnt += 1
        st.pop()
    else:
        dup_cnt = 0
    st.append(i)

    print(i, check)
print(ans)
'''

import sys
import bisect
input = sys.stdin.readline
INF = 1<<31

n = int(input())
h = [INF] + [int(input()) for _ in range(n)] #bisect 사용하기 위해 음수로 저장
st = [0]
ans = 0
for i in range(1, n+1):

    check = 0
    lp = bisect.bisect_left(st, -h[i], key = lambda x : -h[x])
    rp = bisect.bisect_right(st, -h[i], key = lambda x : -h[x])
    if lp > 1:
        ans += 1
        check += 1
    if lp < len(st):
        ans += len(st) - lp

        check += len(st) - lp
    while h[st[-1]] < h[i]:
        st.pop()
    st.append(i)

print(ans)