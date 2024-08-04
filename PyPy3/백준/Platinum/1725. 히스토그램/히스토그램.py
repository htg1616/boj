import sys
input = sys.stdin.readline

n = int(input())
h = [0] + [int(input()) for _ in range(n)] + [0]
st = [0]
ans = 0
for i in range(1, n+2):
    while h[st[-1]] > h[i]:
        check = st.pop()
        ans = max(ans, h[check]*(i-st[-1]-1))
    st.append(i)
print(ans)